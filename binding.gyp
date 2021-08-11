{
    "targets": [
        {
            "target_name": "msg.node",
            "sources": [
                "message_box.cc",
            ],
            "conditions": [
                ['OS=="mac"', {
                    "sources": [
                        "mac.h",
                        "mac.mm"
                    ],
                }]
            ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ],
            'defines': ['NAPI_DISABLE_CPP_EXCEPTIONS'],
            "xcode_settings": {
                "MACOSX_DEPLOYMENT_TARGET": "10.10",
                "SYSTEM_VERSION_COMPAT": 1,
                "OTHER_CPLUSPLUSFLAGS": ["-std=c++14", "-stdlib=libc++"],
                "OTHER_LDFLAGS": [
                    "-framework AppKit"
                ]
            }
        }
    ]
}
