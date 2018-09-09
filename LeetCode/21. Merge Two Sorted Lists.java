/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode p = dummy;
        ListNode pointer1 = l1;
        ListNode pointer2 = l2;

        while(pointer1 != null && pointer2 != null) {
        	if(pointer1.val < pointer2.val) {
        		p.next = pointer1;
        		p = p.next;
        		pointer1 = pointer1.next;
        	}
        	else {
        		p.next = pointer2;
        		p = p.next;
        		pointer2 = pointer2.next;
        	}
        }

        if(pointer1 == null) p.next = pointer2;
        if(pointer2 == null) p.next = pointer1;

        return dummy.next;
    }
}