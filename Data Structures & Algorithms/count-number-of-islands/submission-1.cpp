class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(bfs(grid, i, j))
                    res++;
            }
        }
        return res;
    }

    bool bfs(vector<vector<char>>& grid, int i, int j){
        if(grid[i][j]=='0')
            return false;

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int,int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        q.emplace(i,j);
        grid[i][j]='0';
        while(!q.empty()){
            auto x = q.front();
            q.pop();

            for(auto d: dirs){
                int nx = d.first + x.first;
                int ny = d.second + x.second;
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]=='1'){
                    grid[nx][ny]='0';
                    q.emplace(nx,ny);
                }
            }
        }
        return true;
    }
};
