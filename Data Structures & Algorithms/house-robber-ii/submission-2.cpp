class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        auto solve = [&](int a, int b){
            if(b-a+1==1)
                return nums[a];
            int prev2 = nums[a];
            int prev1 = max(nums[a], nums[a+1]);
            for(int i=a+2;i<=b;i++){
                int tmp = prev1;
                prev1 = max(prev1, nums[i] + prev2);
                prev2 = tmp;
            }
            return prev1;
        };
        return max(solve(0, nums.size()-2), solve(1, nums.size()-1));
    }
};
