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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s = l1->val + l2->val;
        int c = s >= 10;
        ListNode *result = new ListNode(s % 10);
        ListNode *temp = result;
        for (l1 = l1->next, l2 = l2->next; 
             l1 != NULL && l2 != NULL;
             l1 = l1->next, l2 = l2->next) {
            s = l1->val + l2->val + c;
            temp->next = new ListNode(s % 10);
            temp = temp->next;
            c = s >= 10;
        }
        for (ListNode *l = l1 == NULL ? l2 : l1; l != NULL; l = l->next) {
            s = l->val + c;
            temp->next = new ListNode(s % 10);
            temp = temp->next;
            c = s >= 10;
        }
        if (c) {
            temp->next = new ListNode(1);
        }
        return result;
    }
};
