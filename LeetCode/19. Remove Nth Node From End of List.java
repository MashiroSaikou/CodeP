/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
    	ListNode dummy = new ListNode(0);
    	dummy.next = head;
        ListNode firstFlag = dummy;
        ListNode secFlag = dummy;
        for(int i = 0; i < n; i++) {
        	secFlag = secFlag.next;
        }

        while(secFlag.next != null) {
        	firstFlag = firstFlag.next;
        	secFlag = secFlag.next;
        }

        firstFlag.next = firstFlag.next.next;
        return dummy.next;
    }
}