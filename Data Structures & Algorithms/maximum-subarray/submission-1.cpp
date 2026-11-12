class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res =INT_MIN;
        int cursum=0;
        for(auto& n: nums){
            cursum = max(n, cursum + n);
            res = max(cursum, res);
        }
        return res;
    }
};
