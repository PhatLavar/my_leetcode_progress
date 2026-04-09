#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1, right = 1;
        int size = (int)nums.size();
        vector<int> output(size, 1);

        for (int i = 0; i < size; i++) {
            output[i] *= left;
            left *= nums[i];
        }

        for (int i = size - 1; i >= 0; i--) {
            output[i] *= right;
            right *= nums[i];
        }

        return output;
    }
};