/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    var split = path.split('\/');
    var stack = [];
    split.forEach(function(name) {
        if ('.' === name || '' === name) {
            return;
        } else if ('..' === name) {
            stack.pop();
        } else {
            stack.push(name);
        }
    });
    return '\/' + stack.join('\/');
};