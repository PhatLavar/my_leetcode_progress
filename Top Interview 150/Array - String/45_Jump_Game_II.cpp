#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int near = 0; 
        int far = 0; 
        int jumps = 0;

        while (far < (int)nums.size() - 1) {
            int far_most = 0;
            for (int i = near; i <= far; i++) {
                far_most = max(far_most, i + nums[i]);
            }

            near = far + 1;
            far = far_most;
            jumps++;
        }

        return jumps;
    }
};