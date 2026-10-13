class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
            return false;

        unordered_map<int, vector<int>> mp;
        for(auto e: edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        unordered_set<int> vis;
        
        return nocycle(mp, vis, 0, -1) && vis.size() == n;
    }

    bool nocycle(unordered_map<int, vector<int>>& mp, unordered_set<int>& vis, int i, int p){
        if(vis.count(i))
            return false;
        vis.insert(i);
        for(auto n: mp[i]){
            if(n!=p && !nocycle(mp, vis, n, i))
                return false;
        }
        return true;
    }
};
