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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        ListNode *node = new ListNode(0);
        ListNode *prev = node;
        ListNode *last = head;
        prev->next = head;
        while (last) {
            for (int i = 1; i < k; ++i) {
                if (!last->next) {
                    return node->next;
                }
                last = last->next;
            }
            ListNode *t = prev->next;
            while (prev->next != last) {
                ListNode *q = prev->next->next;
                prev->next->next = last->next;
                last->next = prev->next;
                prev->next = q;
            }
            prev = t;
            last = t->next;
        }
        return node->next;
    }
};
