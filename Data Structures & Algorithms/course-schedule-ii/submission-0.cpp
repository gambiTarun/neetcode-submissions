class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        for(auto p: prerequisites){
            adj[p[0]].push_back(p[1]);
        }
        vector<int> vis(numCourses);
        vector<int> res;
        for(int i=0;i<numCourses;i++){
            if(iscycle(adj, i, vis, res)){
                return {};
            }
        }
        // reverse(res.begin(), res.end());
        return res.size()==numCourses ? res : vector<int>();
    }

    bool iscycle(vector<vector<int>>& adj, int i, vector<int>& vis, vector<int>& res){
        if(vis[i]==1)
            return true;
        if(vis[i]==2)
            return false;
        vis[i]=1;
        for(auto n: adj[i]){
            if(iscycle(adj, n, vis, res))
                return true;
        }
        res.push_back(i);
        vis[i]=2;
        return false;
    }
};
