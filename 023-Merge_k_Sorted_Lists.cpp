/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    class NodeCompare {
    public:
        bool operator()(ListNode* lhs, ListNode* rhs) const {
            return rhs->val < lhs->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        priority_queue<ListNode*, vector<ListNode*>, NodeCompare> nodes;
        for (auto node : lists) {
            if (node) {
                nodes.push(node);
            }
        }
        while (nodes.size() > 1) {
            ListNode *q = nodes.top();
            nodes.pop();
            p->next = q;
            p = p->next;
            if (q->next) {
                nodes.push(q->next);
            }
        }
        if (!nodes.empty()) {
            p->next = nodes.top();
        }
        return head->next;
    }
};
