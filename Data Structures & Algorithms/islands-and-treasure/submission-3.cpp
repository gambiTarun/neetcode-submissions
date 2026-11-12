class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                    q.push(make_pair(i,j));
            }
        }
        int lev=0;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto& d: dirs){
                int ni=x+d[0];
                int nj=y+d[1];
                if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]==INT_MAX){
                    grid[ni][nj] = grid[x][y]+1;
                    q.push(make_pair(ni,nj));
                }
            }
        }
    }
private:
    vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
};
