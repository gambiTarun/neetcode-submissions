class Solution:
    def getSum(self, a: int, b: int) -> int:
        c = 0
        res = 0
        i = 0
        mask = 0xffffffff
        
        for i in range(32):
            abit = a>>i&1
            bbit = b>>i&1
            bit = c ^ abit ^ bbit
            c = (abit & bbit) | c & (abit ^ bbit)
            if bit:
                res |= (1<<i)

        if res > 0x7fffffff:
            res = ~(res ^ mask)

        return res