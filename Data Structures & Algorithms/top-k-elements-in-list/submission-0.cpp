class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<char, int> count;
        for(auto &n: nums){
            count[n]++;
        }
        priority_queue<pair<int,int>> q;
        for(auto &kv : count)
            q.push({kv.second, kv.first});

        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(q.top().second);
            q.pop();
        }

        return res;
    }
};
