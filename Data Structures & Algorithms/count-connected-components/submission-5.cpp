class Union {
public:
    vector<int> p;
    vector<int> r;

    Union(int n){
        p.resize(n);
        r.resize(n, 1);
        for(int i=0;i<n;i++)
            p[i] = i;
    }

    int find(int x){
        while(p[x] != x){
            p[x] = p[p[x]];
            x = p[x];
        }
        return p[x];
    }

    bool unionset(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px==py)
            return false;

        if(r[px]>r[py])
            swap(px,py);

        r[px] += r[py];
        p[px] = py;
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        Union un(n);
        int res=n;
        for(auto& e: edges){
            if(un.unionset(e[0], e[1]))
                res--;
        }
        return res;
    }
};
