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
    bool isValidBST(TreeNode* root) {
        return isvalid(root, INT_MIN, INT_MAX);
    }

    bool isvalid(TreeNode* root, int min_, int max_){
        if(root==nullptr)
            return true;
        bool val = root->val < max_ && root->val > min_;
        if(root->left){
            val &= root->left->val < root->val && isvalid(root->left, min_, root->val);
        }
        if(root->right){
            val &= root->right->val > root->val && isvalid(root->right, root->val, max_);
        }
        return val;
    }
};
