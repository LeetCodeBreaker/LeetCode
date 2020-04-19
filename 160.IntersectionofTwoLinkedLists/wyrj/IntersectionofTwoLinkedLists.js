/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
  const getLen = (head) => {
    let curr = head;
    let len = 0;
    while (curr) {
      len += 1;
      curr = curr.next;
    }
    return len;
  };

  const lenA = getLen(headA);
  const lenB = getLen(headB);

  let currA = headA;
  let currB = headB;

  if (lenA > lenB) {
    let step = lenA - lenB;
    while (step--) {
      currA = currA.next;
    }
  }
  if (lenB > lenA) {
    let step = lenB - lenA;
    while (step--) {
      currB = currB.next;
    }
  }

  while (currA && currB) {
    if (currA === currB) {
      return currA;
    }
    currA = currA.next;
    currB = currB.next;
  }

  return null;
};

class ListNode {
  consturctor(val) {
    this.val = val;
    this.next = null;
  }
}

const d = new ListNode(8);
d.next = new ListNode(4);
d.next.next = new ListNode(5);

const h1 = new ListNode(4);
h1.next = new ListNode(1);
h1.next.next = d;

const h2 = new ListNode(5);
h2.next = new ListNode(0);
h2.next.next = new ListNode(1);
h2.next.next.next = d;

console.log(getIntersectionNode(h1, h2));
