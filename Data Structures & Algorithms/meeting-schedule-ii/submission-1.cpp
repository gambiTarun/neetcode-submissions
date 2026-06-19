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
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){return a.start < b.start;});
        size_t res = 0;
        for(auto& i: intervals){
            if(pq.empty()){
                pq.push(i.end);
                res = 1;
                continue;
            }
            while(!pq.empty() && i.start >= pq.top())
                pq.pop();
            pq.push(i.end);
            res = max(res, pq.size());
        }
        return res;
    }
};
