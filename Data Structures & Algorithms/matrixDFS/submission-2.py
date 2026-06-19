class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        vis = [[False]*n for _ in range(m)]
        count = 0

        def dfs(i, j):
            nonlocal count 
            vis[i][j] = True
            if i==m-1 and j==n-1:
                count += 1
            for di, dj in [(0,1), (1,0), (-1,0), (0,-1)]:
                ni, nj = i+di, j+dj
                if 0<=ni<m and 0<=nj<n and not vis[ni][nj] and grid[ni][nj]==0:
                    dfs(ni, nj)
            vis[i][j] = False

        if grid[0][0]==0:
            dfs(0, 0)
        return count