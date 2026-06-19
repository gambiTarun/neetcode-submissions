class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        dp = [False]*len(nums)
        for i in range(len(nums)-1,-1,-1):
            if i+nums[i] >= len(nums)-1:
                dp[i] = True
                continue

            dp[i] = any(dp[i+n] for n in range(nums[i]+1))

        print("deb", dp)
        return dp[0]

            
