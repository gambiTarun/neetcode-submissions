class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        for i in range(32):
            shift = 31 - 2*i
            bit = (n & (1<<i))
            res ^=  bit << shift if shift>0 else bit >> -shift

        return res