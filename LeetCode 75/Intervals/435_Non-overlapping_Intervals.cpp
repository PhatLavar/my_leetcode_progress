#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        int removed = 0;
        int prev_end = intervals[0][1];

        for (int i = 1; i < (int)intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start < prev_end) removed++;
            else prev_end = end;
        }

        return removed;
    }
};