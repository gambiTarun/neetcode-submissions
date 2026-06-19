from collections import defaultdict

class Graph:
    
    def __init__(self):
        self.adj = {}

    def addEdge(self, src: int, dst: int) -> None:
        if src not in self.adj:
            self.adj[src] = set()
        if dst not in self.adj:
            self.adj[dst] = set()
        self.adj[src].add(dst)

    def removeEdge(self, src: int, dst: int) -> bool:
        if src in self.adj and dst in self.adj[src]:
            self.adj[src].remove(dst)
            return True
        return False

    def hasPath(self, src: int, dst: int) -> bool:
        vis = defaultdict(bool)
        for s in self.adj.keys():
            vis[s] = False

        def dfs(n):
            vis[n] = True
            if n==dst:
                return True
            for neig in self.adj[n]:
                if not vis[neig] and dfs(neig):
                    return True
            return False

        return dfs(src)