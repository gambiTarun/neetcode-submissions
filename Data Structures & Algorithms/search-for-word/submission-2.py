class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])
        vis = set()

        def dfs(i,j,s):
            if not(((i,j) not in vis) and i>=0 and i<m and j>=0 and j<n and word[s]==board[i][j]):
                return False

            if s==len(word)-1:
                return True
            vis.add((i,j))

            for dx,dy in ((0,1),(1,0),(-1,0),(0,-1)):
                ni, nj = i+dx, j+dy
                if dfs(ni,nj,s+1):
                    return True

            vis.remove((i,j))

        for i in range(m):
            for j in range(n):
                if dfs(i,j,0):
                    return True

        return False