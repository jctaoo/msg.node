#include <nan.h>

#include <iostream>

#ifdef _WIN32
#define IS_SUPPORTED_PLATFORM true
#endif

#ifdef __APPLE__
#include "mac.h"
#define IS_SUPPORTED_PLATFORM true
#endif

#ifdef __linux__
#define IS_SUPPORTED_PLATFORM false
#endif

#if !defined IS_SUPPORTED_PLATFORM
cerr << "Unsupported Platform";
exit(EXIT_FAILURE);
#endif

const char* ToCString(const v8::String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}

void MessageBox(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();

  if (info.Length() != 1) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  if (!info[0]->IsString()) {
    Nan::ThrowTypeError("Argument should be a string");
    return;
  }

  v8::String::Utf8Value arg0_v8_str(isolate, info[0]);
  const char* arg0 = ToCString(arg0_v8_str);

  doAlert(arg0);
}

void Init(v8::Local<v8::Object> exports) {
  v8::Local<v8::Context> context = exports->CreationContext();

  exports->Set(context, Nan::New("messageBox").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(MessageBox)
                   ->GetFunction(context)
                   .ToLocalChecked());
}

NODE_MODULE(addon, Init)
