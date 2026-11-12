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
        if(!root)
            return true;
        
        return validBST(root->left, root->val, INT_MIN) && validBST(root->right, INT_MAX, root->val);
    }
    bool validBST(TreeNode* n, int max, int min){
        if(!n)
            return true;

        return n->val < max && n->val > min && validBST(n->left, n->val, min) && validBST(n->right, max, n->val);
    }
};
