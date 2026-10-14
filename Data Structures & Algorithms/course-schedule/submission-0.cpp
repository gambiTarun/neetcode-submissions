class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj;
        for(auto p: prerequisites){
            adj[p[0]].push_back(p[1]);
        }
        vector<int> vis(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(iscycle(i, adj, vis))
                return false;
        }

        return true;
    }

    bool iscycle(int i, map<int, vector<int>>& adj, vector<int>& vis){
        if(vis[i]==1){
            return true;
        }
        else if(vis[i]==0){
            vis[i]=1;
            for(auto n: adj[i]){
                if(iscycle(n, adj, vis)){
                    return true;
                }
            }
            vis[i]=2;
        }
        return false;
    }
};
