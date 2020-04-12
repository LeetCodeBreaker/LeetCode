/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
	this.capacity = capacity;
	this.map = new Map();
	this.head = {};
	this.tail = this.head;
};

LRUCache.prototype.removeNode = function(node) {
	if (node === this.tail) {
		this.tail = node.prev;
	}
	if (node.next) {
		node.next.prev = node.prev;
	}
	node.prev.next = node.next;
};

LRUCache.prototype.insertNode = function(node) {
	node.prev = this.head;
	node.next = this.head.next;
	if (this.head.next) {
		this.head.next.prev = node;
	}
	this.head.next = node;

	if (this.head === this.tail) {
		this.tail = node;
	}
};

LRUCache.prototype.updateNode = function(node) {
	this.removeNode(node);
	this.insertNode(node);
};

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
	if (!this.map.has(key)) {
		return -1;
	}
	const node = this.map.get(key);
	this.updateNode(node);
	return node.value;
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
	if (this.map.has(key)) {
		const node = this.map.get(key);
		node.value = value;
		this.updateNode(node);
		return;
	}
	const node = {key, value};
	this.map.set(key, node);
	this.insertNode(node);

	if (this.map.size > this.capacity) {
		this.map.delete(this.tail.key);
		this.removeNode(this.tail);
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
