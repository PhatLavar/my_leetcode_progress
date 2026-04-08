#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> sumLeft(n, 0);
        vector<int> sumRight(n, 0);

        for (int i = 1; i < n; i++) {
            sumLeft[i] = sumLeft[i - 1] + nums[i - 1];
        }

        for (int j = n - 2; j >= 0; j--) {
            sumRight[j] = sumRight[j + 1] + nums[j + 1];
        }

        for (int i = 0; i < n; i++) {
            if (sumLeft[i] == sumRight[i]) return i;
        }

        return -1;
    }
};