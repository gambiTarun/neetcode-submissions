"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        if len(intervals)==0:
            return True
        ints = sorted(intervals, key=lambda x: (x.start, x.end))

        prev_end = ints[0].end
        for i in ints[1:]:
            if i.start < prev_end:
                return False
            prev_end = i.end

        return True