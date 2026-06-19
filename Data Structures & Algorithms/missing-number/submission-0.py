class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        in_ = [False]*1000
        for i in nums:
            in_[i] = True
        
        return in_.index(False)