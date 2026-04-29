#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int DP(vector<int>& dp, vector<int>& nums, int n) {
        if (n == 0) return dp[n] = 0;
        if (n == 1) return dp[n] = nums[n - 1];
        if (dp[n] != -1) return dp[n];

        return dp[n] = max(
            DP(dp, nums, n - 1),
            DP(dp, nums, n - 2) + nums[n - 1]
        );
    }

public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> maximum(n + 1, -1);
        return DP(maximum, nums, n);
    }
};