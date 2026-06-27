class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = 0;
        int res=INT_MIN;
        for(auto& n: nums){
            s = max(n, n+s);
            res = max(res, s);
        }
        return res;
    }
};
