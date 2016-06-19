/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    var arrA = a.split('').reverse();
    var arrB = b.split('').reverse();
    var result = [], i, carry = 0, n;
    for (i = 0; i < arrA.length || i < arrB.length; i++) {
        n = parseInt(arrA[i] || 0) + parseInt(arrB[i] || 0) + carry;
        result.push(n % 2);
        carry = (n >= 2) ? 1 : 0;
    }
    if (carry) {
        result.push(1);
    }
    return result.reverse().join('');
};