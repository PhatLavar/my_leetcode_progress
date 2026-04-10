#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiants, dires;
        int n = (int)senate.length();
        
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') radiants.push(i);
            else dires.push(i);
        }

        while (!radiants.empty() && !dires.empty()) {
            int r = radiants.front(); radiants.pop();
            int d = dires.front(); dires.pop();

            if (r < d) radiants.push(r + n);
            else dires.push(d + n);
        }

        return dires.empty() ? "Radiant" : "Dire";
    }
};