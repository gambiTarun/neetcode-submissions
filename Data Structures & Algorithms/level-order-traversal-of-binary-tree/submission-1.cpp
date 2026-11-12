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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()){
            int ls = q.size();
            vector<int> lev(ls);
            for(int i=0;i<ls;i++){
                TreeNode* x = q.front();
                q.pop();
                lev[i] = x->val;
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
            }
            res.push_back(lev);
        }
        return res;
    }
};
