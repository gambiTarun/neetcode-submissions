class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        auto solve = [&](int a, int b){
            if(b-a+1==1)
                return nums[a];
            vector<int> dp(b-a+1, 0);
            dp[0] = nums[a];
            dp[1] = max(nums[a], nums[a+1]);
            for(int i=2;i<=b-a;i++){
                dp[i] = max(dp[i-1], nums[a+i] + dp[i-2]);
            }
            return dp[b-a];
        };
        cout << solve(0, nums.size()-2) << endl;
        cout << solve(1, nums.size()-1) << endl;
        return max(solve(0, nums.size()-2), solve(1, nums.size()-1));
    }
};
