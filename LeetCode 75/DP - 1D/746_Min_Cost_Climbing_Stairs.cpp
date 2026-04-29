#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int DP(vector<int>& dp, vector<int>& cost, int n) {
        if (n == 0 || n == 1) return dp[n] = 0;
        if (dp[n] != -1) return dp[n];

        return dp[n] = min(
            DP(dp, cost, n - 1) + cost[n - 1],
            DP(dp, cost, n - 2) + cost[n - 2]
        );
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int)cost.size();
        vector<int> minimum(n + 1, -1);
        return DP(minimum, cost, n);
    }
};