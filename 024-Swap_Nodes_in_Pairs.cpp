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
    ListNode* swapPairs(ListNode* head) {
        ListNode *k = new ListNode(0);
        ListNode *p = k;
        p->next = head;
        while (p->next && p->next->next) {
            ListNode *q = p->next->next;
            p->next->next = q->next;
            q->next = p->next;
            p->next = q;
            p = p->next->next;
        }
        return k->next;
    }
};
