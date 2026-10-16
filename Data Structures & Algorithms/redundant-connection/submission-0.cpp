class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indeg(n+1, 0);
        vector<vector<int>> adj(n+1, vector<int>());
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indeg[e[0]]++;
            indeg[e[1]]++;
        }

        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indeg[i]==1) q.push(i);
        }

        while(!q.empty()){
            auto x = q.front();
            q.pop();
            indeg[x]--;
            for(auto& nei: adj[x]){
                indeg[nei]--;
                if(indeg[nei]==1)   q.push(nei);
            }
        }

        for(int i=n-1;i>=0;i--){
            if(indeg[edges[i][0]] == 2 && indeg[edges[i][1]]==2)
                return {edges[i][0], edges[i][1]};
        }
        return {};
    }
};
