#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1;
        int right = 1;

        int n = (int)nums.size();
        vector<int> output(n, 1);

        for (int i = 0; i < n; i++) {
            output[i] *= left;
            left *= nums[i];
        }

        for (int j = n - 1; j >= 0; j--) {
            output[j] *= right;
            right *= nums[j];
        }

        return output;
    }
};