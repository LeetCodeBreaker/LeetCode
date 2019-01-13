/**
 * Definition for binary tree with next pointer.
 * function TreeLinkNode(val) {
 *     this.val = val;
 *     this.left = this.right = this.next = null;
 * }
 */

/**
 * @param {TreeLinkNode} root
 * @return {void} Do not return anything, modify tree in-place instead.
 */
var connect = function(root) {
    if (!root) return;
    root.next = null;
    let parent = root;
    let first = root.left || root.right
    while (first) {
        let curr = first;
        let next = null;
        let nextFirst = curr.left || curr.right;
        while (parent) {
            next = curr === parent.left ? parent.right : (parent.left || parent.right);
            if (!next) parent = parent.next;
            else {
                curr.next = next;
                curr = next;
                if (next === parent.right) parent = parent.next;
                if (!nextFirst) nextFirst = curr.left || curr.right;
            }
        }
        curr.next = null;
        parent = first;
        first = nextFirst;
    }
};
