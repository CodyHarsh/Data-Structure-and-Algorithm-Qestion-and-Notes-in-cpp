/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode l3 = new ListNode();
        ListNode head = l3;
        int num = 0;
        int h = 0;
        
        while(l1 != null || l2 != null){
            if(l1 != null && l2 != null)
                num = l1.val + l2.val + h;
            else if(l1 == null)
                num = l2.val + h;
            else if(l2 == null)
                num = l1.val + h;
            
            if(l1 != null)
                l1 = l1.next;
            if(l2 != null)
                l2 = l2.next;
            
            if(num > 9){
                l3.val = num%10;
                h = 1;
            }
            else{
                l3.val = num;
                h = 0;
            }
            
            if(l1 != null || l2 != null){
                l3.next = new ListNode();
                l3 = l3.next;
            }
        }
        if(h == 1){
            l3.next = new ListNode(1);
        }
        return head;
    }
}
