#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#import <AppKit/NSAlert.h>
#include "mac.h"

void doAlert(const char* message) {
    NSAlert *alert = [[NSAlert alloc] init];
    NSString *userMsg = [NSString stringWithFormat:@"%@%s", @"👋 Hi there ", message];

    [alert addButtonWithTitle:@"OK"];
    [alert setMessageText:userMsg];
    [alert setInformativeText:@"Welcome to msg.node"];

    if ([alert runModal] == NSAlertFirstButtonReturn) {
    }
}
