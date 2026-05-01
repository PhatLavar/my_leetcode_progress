#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int DP(vector<vector<int>>& dp, int m, int n) {
        if (m < 0 || n < 0) return 0;
        if (m == 0 || n == 0) return dp[m][n] = 1;
        if (dp[m][n] != -1) return dp[m][n];

        return dp[m][n] = (
            DP(dp, m - 1, n) +
            DP(dp, m, n - 1)
        );
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(m, vector<int>(n, -1));
        return DP(path, m - 1, n - 1);
    }
};