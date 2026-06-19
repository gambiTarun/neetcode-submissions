from collections import defaultdict

class Solution:
    def topologicalSort(self, n: int, edges: List[List[int]]) -> List[int]:
        adj = defaultdict(list)
        vis = {i:0 for i in range(n)}

        for e in edges:
            adj[e[0]].append(e[1])

        res=[]
        def iscycle(node):
            if vis[node] == 1:
                return True
            if vis[node] == 2:
                return False
            
            vis[node] = 1
            for x in adj[node]:
                if iscycle(x):
                    return True
            
            vis[node] = 2
            res.append(node)
            return False
            
        for i in range(n):
            if vis[i]==0 and iscycle(i):
                return []

        return res[::-1]
