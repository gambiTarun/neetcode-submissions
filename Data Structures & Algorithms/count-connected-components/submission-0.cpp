class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        set<int> vis;

        int res=0;
        for(int i=0;i<n;i++){
            if(!vis.count(i)){
                dfs(adj, vis, i);
                res++;
            }
        }
        return res;
    }

    void dfs(unordered_map<int, vector<int>> &adj, set<int> &vis, int i){
        if(vis.count(i)){
            return;
        }
        vis.insert(i);
        for(auto &n: adj[i]){
            dfs(adj, vis, n);
        }
    }
};
