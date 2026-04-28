#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1;
        int max = 1;
        for (int pile : piles) if (pile > max) max = pile;

        while (min < max) {
            int mid = min + (max - min) / 2;
            long long hours = 0;

            for (int pile : piles) hours += ceil((double)pile / mid);
            if (hours <= h) max = mid;
            else min = mid + 1;
        }

        return min;
    }
};