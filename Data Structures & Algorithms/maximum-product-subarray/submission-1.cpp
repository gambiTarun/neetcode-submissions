class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int curmin=1;
        int curmax=1;
        for(int n:nums){
            int tmp = curmax * n;
            curmax = max(max(curmin*n, tmp), n);
            curmin = min(min(curmin*n, tmp), n);
            res = max(res, curmax);
        }
        return res;
    }
};
