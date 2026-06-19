class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        xor = len(nums)
        for i in range(len(nums)):
            xor ^= nums[i] ^ i

        return xor