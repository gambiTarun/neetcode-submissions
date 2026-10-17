class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto& t: times){
            if(adj.count(t[0])==0)
                adj[t[0]] = {};
            adj[t[0]].emplace_back(t[1], t[2]);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        set<int> vis;

        int res=0;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            if(vis.count(x.second))
                continue;
            vis.insert(x.second);
            res = x.first;

            for(auto& n: adj[x.second]){

                if(vis.count(n.first)==0){
                    pq.push({res+n.second, n.first});
                }
            }
        }
        return vis.size()==n ? res : -1;
    }
};
