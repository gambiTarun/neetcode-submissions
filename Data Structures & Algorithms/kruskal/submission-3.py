import heapq

class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
    
    def find(self, x):
        if self.par[x] != x:
            x = self.find(self.par[x])
        return x

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px==py:
            return False
        self.par[px] = py
        return True

class Solution:
    def minimumSpanningTree(self, n: int, edges: List[List[int]]) -> int:
        pq = []
        for e in edges:
            heapq.heappush(pq, (e[2], e[0], e[1]))

        uf = UnionFind(n)
        res, e = 0, 0

        while e < n-1 and pq:
            l, s, d = heapq.heappop(pq)

            if uf.union(s,d):
                e += 1
                res += l

        return res if e == n-1 else -1