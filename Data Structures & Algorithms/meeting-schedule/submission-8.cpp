/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()<=1)
            return true;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        int last_end = intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start < last_end)
                return false;
            last_end = max(last_end, intervals[i].end);
        }
        return true;
    }
};
