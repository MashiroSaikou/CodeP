/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        int length = 0;
        for(ListNode i = head; i != null; i = i.next) {
        	length ++;
        }

        ListNode p, q, r;
        ListNode start = head;
        ListNode link = dummy;

        int num2reverse = length/k;
        for(int i = 0; i < num2reverse; i ++) {
        	p = start; q = p.next; 
            r = q.next;
        	for(int j = 0; j < k-2; j++) {
                //if(r == null) System.out.printf("hello\n");
        		q.next = p;
        		p = q;
        		q = r;
        		r = r.next;
        	}

        	/*关节部分*/
            
        	link.next = q;
        	link = start;
        	start.next = r;
            start = r;
            q.next = p;
            //System.out.printf("%d %d\n",start.val, length);
        }
        return dummy.next;
    }
}
