/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto kl = findInterval(intervals, newInterval.start);
        auto kr = findInterval(intervals, newInterval.end);
        auto it1 = intervals.begin() + kl.second;
        auto it2 = kr.first ? intervals.begin() + kr.second + 1 : intervals.begin() + kr.second;
        int vl = kl.first ? intervals[kl.second].start : newInterval.start;
        int vr = kr.first ? intervals[kr.second].end : newInterval.end;
        vector<Interval> vec(intervals.begin(), it1);
        vec.push_back(Interval(vl, vr));
        vec.insert(vec.end(), it2, intervals.end());
        return vec;
    }
private:
    pair<bool, int> findInterval(vector<Interval>& intervals, int val) {
        int l = 0, r = intervals.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (intervals[m].end < val) {
                l = m + 1;
            } else if (intervals[m].start > val) {
                r = m;
            } else {
                return make_pair(true, m);
            }
        }
        return make_pair(false, l);
    }
};
