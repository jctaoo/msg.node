const msg = require("bindings")("msg.node");

exports.messageBox = function(name) {
    msg.messageBox(name);
}