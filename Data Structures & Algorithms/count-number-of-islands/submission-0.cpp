class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs_vis(i,j,grid);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs_vis(int i, int j, auto &g){
        if(i<0 || i>=g.size() || j<0 || j>=g[0].size() || g[i][j]=='0')
            return;
        g[i][j]='0';
        dfs_vis(i+1,j,g);
        dfs_vis(i,j+1,g);
        dfs_vis(i-1,j,g);
        dfs_vis(i,j-1,g);
    }
};
