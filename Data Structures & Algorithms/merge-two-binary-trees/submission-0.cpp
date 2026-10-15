/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr)
            return nullptr;

        int node_val = root1 ? root1->val : 0;
        node_val += root2 ? root2->val : 0;

        TreeNode* node = new TreeNode(node_val);
        node->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
        node->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
        return node;
    }
};