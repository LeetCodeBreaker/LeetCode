/**
 * initialize your data structure here.
 */
var MinStack = function() {
  this.stack = [];
  this.minIndex = [];
};

/**
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
  this.stack.push(x);
  const lastIndex = this.minIndex[this.minIndex.length - 1];
  if (this.minIndex.length === 0 || x < this.stack[lastIndex]) {
    this.minIndex.push(this.minIndex.length);
  } else {
    this.minIndex.push(lastIndex);
  }
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
  this.stack.pop();
  this.minIndex.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
  return this.stack[this.stack.length - 1];
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
  return this.stack[this.minIndex[this.minIndex.length - 1]];
};

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */

const o = new MinStack();
o.push(3);
o.push(7);
o.push(0);
o.push(1);
console.log(o.getMin(), 0);
o.pop();
o.pop();
console.log(o.getMin(), 3);
