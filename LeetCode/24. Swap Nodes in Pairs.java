
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode i = dummy;
        ListNode j, k;
        while(i.next != null || i.next.next != null) {
        	j = i.next;
        	k = i.next.next;
        	i.next = k;
        	j.next = k.next;
        	k.next = j;
            
            i = i.next.next;
        }

        return dummy.next;
    }
}