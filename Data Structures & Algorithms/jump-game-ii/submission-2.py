class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [float("inf")]*len(nums)
        dp[-1] = 0

        for i in range(len(nums)-2, -1, -1):
            dp[i] = 1 + min(dp[min(len(nums)-1, i+n)] for n in range(nums[i]+1))

        return dp[0]