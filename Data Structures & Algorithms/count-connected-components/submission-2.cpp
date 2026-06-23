class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) : parent(n), rank(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int findp(int x){
        if(x==parent[x])
            return x;
        parent[x] = findp(parent[x]);
        return parent[x];
    }

    bool union_(int a, int b){
        int x = findp(a);
        int y = findp(b);
        if(x==y)
            return false;
        if(rank[x] < rank[y])
            swap(x, y);
        parent[y] = x;
        rank[x] += rank[y];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int res = n;
        for(auto &e: edges){
            if(dsu.union_(e[0], e[1]))
                res--;
        }
        return res;
    }
};
