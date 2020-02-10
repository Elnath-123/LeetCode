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
    ListNode* tailInsert(ListNode *head, int num){
        if(head == NULL){
            return new ListNode(num);
        }
        ListNode* copy_head = head;
        ListNode* p = new ListNode(num);
        while(copy_head->next) copy_head = copy_head->next;
        copy_head->next = p;
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int co, cur;
        co = cur = 0;
        ListNode* head = NULL;
        do{
            int sum = l1->val + l2->val + co;
            cur = sum % 10;
            co = sum / 10;
            head = tailInsert(head, cur);
            l1 = l1->next;
            l2 = l2->next;
        } while(l1 && l2);

        while(l1){
            head = tailInsert(head, (l1->val + co) % 10);
            co = (l1->val + co) / 10;
            l1 = l1->next;
        }

        while(l2){
            head = tailInsert(head, (l2->val + co) % 10);
            co = (l2->val + co) / 10;
            l2 = l2->next;
        }

        if(co == 1){
            head = tailInsert(head, co);
        }
        return head;
    }
};