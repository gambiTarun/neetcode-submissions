class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<vector<int>> res;
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(bfs(heights, i, j, res)){
                    res.insert({i, j});
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }

    bool bfs(vector<vector<int>>& h, int i, int j, set<vector<int>>& res){
        queue<pair<int, int>> q;
        q.push({i, j});
        bool flows_in_atl=false;
        bool flows_in_pac=false;
        vector<pair<int, int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
        set<vector<int>> vis;
        while(!q.empty()){
            auto [ni, nj] = q.front();
            q.pop();
            if(nj==h[0].size()-1 || ni==h.size()-1)
                flows_in_atl=true;
            if(nj==0 || ni==0)
                flows_in_pac=true;
            if(flows_in_atl && flows_in_pac)
                return true;
            for(auto& [di, dj]: dirs){
                int newi=ni+di;
                int newj=nj+dj;
                if(newi>=0 && newi<h.size() && newj>=0 && newj<h[0].size() && vis.count({newi, newj})==0 && h[newi][newj] <= h[ni][nj]){
                    vis.insert({newi, newj});
                    q.push({newi, newj});
                }
            }
        }
        return flows_in_atl && flows_in_pac;
    }
};
