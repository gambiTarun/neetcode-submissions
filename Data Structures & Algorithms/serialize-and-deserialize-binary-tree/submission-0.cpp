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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> preorder;
        dfsserialize(root, preorder);
        return join(preorder, ',');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> preorder = split(data, ',');
        int i=0;
        return dfsdeserialize(preorder, i);
    }

    void dfsserialize(TreeNode* root, vector<string> &pre){
        if(!root){
            pre.push_back("N");
            return;
        }
        pre.push_back(to_string(root->val));
        dfsserialize(root->left, pre);
        dfsserialize(root->right, pre);
    }

    TreeNode* dfsdeserialize(vector<string> &pre, int &i){
        if(pre[i]=="N"){
            i++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(std::stoi(pre[i]));
        i++;
        node->left = dfsdeserialize(pre, i);
        node->right = dfsdeserialize(pre, i);
        return node;
    }

    vector<string> split(const string& s, char delim){
        vector<string> elems;
        stringstream ss(s);
        string elem;
        while(getline(ss, elem, delim)){
            elems.push_back(elem);
        }
        return elems;
    }

    string join(vector<string> &pre, char delim){
        ostringstream ss;
        for(int i=0; i<pre.size(); i++){
            if(i!=0)
                ss << delim;
            ss << pre[i];
        }
        return ss.str();
    }
};
