#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int result = 0;
        for (int num : nums) result ^= num;
        return result;
    }
};