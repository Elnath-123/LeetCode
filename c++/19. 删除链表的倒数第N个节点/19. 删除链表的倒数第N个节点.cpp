/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* q = head;
        while(n > 0) {
            q = q->next;
            n--;
        }
        if(q == NULL){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while(q->next){
            p = p->next;
            q = q->next;
        }
        ListNode* temp = p->next;
        p->next = temp->next;
        delete temp;
        return head;
    
    }
};