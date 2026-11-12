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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        height(root, res);
        return res;
    }

    int height(TreeNode* n, int& d){
        if(!n)
            return 0;
        int lh = height(n->left, d);
        int rh = height(n->right, d);
        d = max(d, lh + rh);
        return 1 + max(lh, rh);
    }
};
