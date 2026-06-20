class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        for(int i=n-1;i>=0;i--){
            if(i+1==n){
                dp[i] = 1;
            }
            if(i+2==n){
                dp[i] = 1;
            }
            dp[i] += i+1<=n ? dp[i+1] : 0;
            dp[i] += i+2<=n ? dp[i+2] : 0;
        }
        return dp[0];
    }
};
