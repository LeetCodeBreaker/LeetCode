/**
 ** @param {string} beginWord
 ** @param {string} endWord
 ** @param {string[]} wordList
 ** @return {string[][]}
 **/
var findLadders = function(beginWord, endWord, wordList) {
	const isNeighbor = (w1, w2) => {
		let diff = false;
		for (let i = 0; i < w1.length; i++) {
			if (w1[i] !== w2[i]) {
				if (diff === true) {
					return false;
				}
				diff = true;
			}
		}
		return diff;
	};

	const map = new Map();
	[beginWord, ...wordList].forEach((word) => {
		if (map.has(word)) {
			return;
		}
		const neighbor = [];
		const currNode = {word, neighbor};
		map.forEach((node) => {
			if (isNeighbor(node.word, word)) {
				node.neighbor.push(currNode);
				neighbor.push(node);
			}
		});
		map.set(word, currNode);
	});
	const endNode = map.get(endWord);
	if (!endNode || endNode.neighbor.length === 0) {
		return [];
	}

	(function() {
		const set = new Set([beginWord]);
		const n = map.get(beginWord);
		n.dis = 0;
		const queue = [n];
		while (queue.length > 0) {
			const currNode = queue.shift();
			for (let node of currNode.neighbor) {
				if (set.has(node.word)) {
					continue;
				}
				node.dis = currNode.dis + 1;
				queue.push(node);
				set.add(node.word);
			}
		}
	})();

	const output = [];
	let path = [];

	const dfs = (node) => {
		path.push(node.word);
		if (node.word === beginWord) {
			output.push(path.slice().reverse());
			path.pop();
			return;
		}
		for (let nextNode of node.neighbor) {
			if (nextNode.dis === node.dis - 1) {
				dfs(nextNode);
			}
		}
		path.pop();
	}

	dfs(endNode);
	return output;
};
