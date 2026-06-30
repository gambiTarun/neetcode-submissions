class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre_prod(nums.size(), 1);
        vector<int> post_prod(nums.size(), 1);
        int n = nums.size();
        for(int i=1; i<n; i++){
            pre_prod[i] = pre_prod[i-1]*nums[i-1];
            post_prod[n-1-i] = post_prod[n-i]*nums[n-i];
        }
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            res[i] = pre_prod[i]*post_prod[i];
        }
        return res;
    }
};
