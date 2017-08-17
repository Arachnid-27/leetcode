/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> saved;
        TreeNode *p = root;
        while (p || !saved.empty()) {
            while (p != NULL) {
                saved.push(p);
                p = p->left;
            }
            p = saved.top();
            saved.pop();
            result.push_back(p->val);
            p = p->right;
        }
        return result;
    }
};
