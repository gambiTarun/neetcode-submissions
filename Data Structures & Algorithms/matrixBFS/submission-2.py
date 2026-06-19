from collections import deque

class Solution:
    def shortestPath(self, grid: List[List[int]]) -> int:
        vis = set()
        m = len(grid)
        n = len(grid[0])
        def bfs(i, j):
            q = deque([(i,j,0)])
            while q:
                xi,xj,l = q.popleft()
                if xi==m-1 and xj==n-1:
                    return l
                for di,dj in [(0,1),(1,0),(-1,0),(0,-1)]:
                    ni,nj = xi+di, xj+dj
                    if 0<=ni<m and 0<=nj<n and (ni,nj) not in vis and grid[ni][nj]==0:
                        vis.add((ni,nj))
                        q.append((ni,nj,l+1))
            return -1

        return bfs(0,0)