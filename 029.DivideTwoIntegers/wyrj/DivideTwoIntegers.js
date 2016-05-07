var divide = function(dividend, divisor) {
    var MAX_INT = Math.pow(2, 31) - 1;
    var sign = (dividend < 0) ^ (divisor < 0);
    var shifted, multi, result = 0;
    
    dividend = Math.abs(dividend);
    divisor = Math.abs(divisor);
    while(dividend >= divisor) {
        shifted = divisor;
        multi = 1;
        while(dividend >= (shifted << 1) && (shifted << 1) > 0) {
            shifted = shifted << 1;
            multi = multi << 1;
        }
        result += multi;
        dividend -= shifted;
    }
    result = (sign) ? -result : result;
    return (result > MAX_INT) ? MAX_INT : result;
};