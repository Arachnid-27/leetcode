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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        int count = 1;
        ListNode *last = head;
        while (last->next != NULL) {
            last = last->next;
            ++count;
        }
        k = count - k % count;
        if (k == count) {
            return head;
        }
        last->next = head;
        for (int i = 1; i < k; ++i) {
            head = head->next;
        }
        ListNode *ans = head->next;
        head->next = NULL;
        return ans;
    }
};
