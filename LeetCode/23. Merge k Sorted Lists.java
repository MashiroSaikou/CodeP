

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void merge(ListNode[] lists, int i, int j, int mergeGap) {
    	ListNode l1 = lists[i];
    	ListNode l2 = lists[j];
    	ListNode dummy = new ListNode(0);
    	ListNode p = dummy;
    	while(l1 != null && l2 != null) {
    		if(l1.val < l2.val) {
    			p.next = l1;
    			l1 = l1.next;
    		}
    		else {
    			p.next = l2;
    			l2 = l2.next;
    		}
    		p = p.next;
    	}
   		if(l1!=null) p.next = l1;
    	if(l2!=null) p.next = l2;
    	lists[i] = dummy.next;
    }
    
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0) return null;
    	for(int mergeGap = 1; mergeGap < lists.length; mergeGap = mergeGap*2) {
    		for(int i = 0; i+mergeGap < lists.length; i += mergeGap*2) {
    			merge(lists, i, i+mergeGap, mergeGap);
    		}
    	}

    	return lists[0];
    }
}

