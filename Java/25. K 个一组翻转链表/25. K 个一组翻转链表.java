/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        int cnt = 1;
        ListNode p = head;
        while(p != null && cnt < k){   
            p = p.next;
            cnt++;
        }
        if(p == null) return head;
        p = p.next;
        ListNode tmp = head.next;
        head.next = reverseKGroup(p, k);
        cnt = 1;
        while(cnt < k){
            ListNode tmp2 = tmp.next;
            tmp.next = head;
            head = tmp;
            tmp = tmp2;
            cnt++;
        }
        return head;
    }
}