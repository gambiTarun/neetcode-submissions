"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        events = []
        for i in intervals:
            events.append((i.start,1))
            events.append((i.end,-1))

        x = 0
        for e in sorted(events):
            print(e)
            x += e[1]
            if x>=2:
                return False

        return True