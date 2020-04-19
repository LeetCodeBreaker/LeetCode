/**
 * @param {number} numerator
 * @param {number} denominator
 * @return {string}
 */
var fractionToDecimal = function(numerator, denominator) {
  if (numerator === 0) {
    return `0`;
  }

  let sign = false;
  if (numerator < 0) {
    sign = !sign;
    numerator = -numerator;
  }
  if (denominator < 0) {
    sign = !sign;
    denominator = -denominator;
  }
  const signString = sign ? '-' : '';
  const decimal = `${signString}${Math.floor(numerator / denominator)}`;
  const arr = [];
  const remain = [];
  numerator = numerator % denominator * 10;
  let repeatIndex = -1;
  while (numerator !== 0 && repeatIndex === -1) {
    arr.push(Math.floor(numerator / denominator));
    remain.push(numerator);
    numerator = numerator % denominator * 10;
    repeatIndex = remain.indexOf(numerator);
  }
  const noRepeat = repeatIndex === -1 ? arr.join('') : arr.slice(0, repeatIndex).join('');
  const repeat = repeatIndex === -1 ? '' : `(${arr.slice(repeatIndex).join('')})`;

  return (noRepeat || repeat) ? `${decimal}.${noRepeat}${repeat}` : decimal;
};

console.log(fractionToDecimal(10, 5));
console.log(fractionToDecimal(1, 5));
console.log(fractionToDecimal(1, 7));
console.log(fractionToDecimal(10, 7));
console.log(fractionToDecimal(1, 333));
console.log(fractionToDecimal(1, 6));
console.log(fractionToDecimal(1, 3));
console.log(fractionToDecimal(-1, 3));
