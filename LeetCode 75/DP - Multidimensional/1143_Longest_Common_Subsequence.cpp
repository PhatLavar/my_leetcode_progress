#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int DP(vector<vector<int>>& dp, string& text1, string& text2, int i, int j) {
        if (i == text1.size() || j == text2.size()) return dp[i][j] = 0;
        if (text1[i] == text2[j]) return 1 + DP(dp, text1, text2, i + 1, j + 1);
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = max(
            DP(dp, text1, text2, i + 1, j),
            DP(dp, text1, text2, i, j + 1)
        );
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = (int)text1.size();
        int n = (int)text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return DP(dp, text1, text2, 0, 0);
    }
};