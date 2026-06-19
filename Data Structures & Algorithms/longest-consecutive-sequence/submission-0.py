from collections import defaultdict

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        counts = defaultdict(int)
        res = 0
        for n in nums:
            if n in counts and counts[n]:
                continue
            counts[n] = counts.get(n-1,0) + counts.get(n+1,0) + 1
            counts[n - counts[n-1]] = counts[n]
            counts[n + counts[n+1]] = counts[n]
            res = max(res, counts[n])

        return res