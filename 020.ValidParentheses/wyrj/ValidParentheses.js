/* 132ms */
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var stack = [];
    for (var i = 0; i < s.length; i++) {
        switch(s[i]) {
            case '(':
            case '{':
            case '[':
                stack.push(s[i]);
            break;
            case ')':
                if ('(' !== stack[stack.length - 1]) {
                    return false;
                }
                stack.pop();
            break;
            case ']':
                if ('[' !== stack[stack.length - 1]) {
                    return false;
                }
                stack.pop();
            break;
            case '}':
                if ('{' !== stack[stack.length - 1]) {
                    return false;
                }
                stack.pop();
            break;
        }
    }
    return (0 === stack.length) ? true : false;
};