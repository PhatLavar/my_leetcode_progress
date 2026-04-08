#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum;
        for (int i = 0; i < k; i++) {
            maxSum += nums[i];
        }

        int sum = maxSum;
        for (int i = k; i < nums.size(); i++) {
            sum = sum + nums[i] - nums[i - k];
            if (sum > maxSum) maxSum = sum;
        }

        return (double)maxSum / k;
    }
};