class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int a=0;
                    dfs(grid, i, j, a);
                    res = max(res, a);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int& a){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1)
            return;
        grid[i][j]=0;
        a++;
        dfs(grid, i+1, j, a);
        dfs(grid, i, j+1, a);
        dfs(grid, i, j-1, a);
        dfs(grid, i-1, j, a);
    }
};
