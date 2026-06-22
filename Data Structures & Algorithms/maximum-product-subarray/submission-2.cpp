class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int curmin=1;
        int curmax=1;
        for(int n:nums){
            int tmp = curmin * n;
            curmin = min(min(curmax*n, tmp), n);
            curmax = max(max(curmax*n, tmp), n);
            res = max(res, curmax);
        }
        return res;
    }
};
