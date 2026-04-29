#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int DP(vector<int>& dp, int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        if (dp[n] != -1) return dp[n];
        return dp[n] = DP(dp, n - 1) + DP(dp, n - 2) + DP(dp, n - 3);
    }

public:
    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        return DP(dp, n);
    }
};