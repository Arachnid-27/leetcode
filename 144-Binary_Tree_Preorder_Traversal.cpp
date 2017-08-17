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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> saved;
        saved.push(root);
        while (!saved.empty()) {
            auto p = saved.top();
            saved.pop();
            if (p != NULL) {
                result.push_back(p->val);
                saved.push(p->right);
                saved.push(p->left);
            }
        }
        return result;
    }
};
