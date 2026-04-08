#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = (int)gain.size();
        vector<int> altitude(n + 1, 0);
        int maxAltitude = 0;

        for (int i = 1; i < n + 1; i++) {
            altitude[i] = altitude[i - 1] + gain[i - 1];
            if (altitude[i] > maxAltitude) maxAltitude = altitude[i];
        }

        return maxAltitude;
    }
};