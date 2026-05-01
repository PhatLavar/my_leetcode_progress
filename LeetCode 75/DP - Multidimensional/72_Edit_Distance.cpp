#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int DP(vector<vector<int>>& dp, string& word1, string& word2, int i, int j) {
        int m = (int)word1.size();
        int n = (int)word2.size();
        if (i == m) return dp[i][j] = n - j;
        if (j == n) return dp[i][j] = m - i;

        if (dp[i][j] != -1) return dp[i][j];
        if (word1[i] == word2[j]) return dp[i][j] = DP(dp, word1, word2, i + 1, j + 1);
        
        // Insert  -->  i      ,  j + 1
        // Delete  -->  i + 1  ,  j
        // Replace -->  i + 1  ,  j + 1
        return dp[i][j] = 1 + min({
            DP(dp, word1, word2, i, j + 1),
            DP(dp, word1, word2, i + 1, j),
            DP(dp, word1, word2, i + 1, j + 1)
        });
    }

public:
    int minDistance(string word1, string word2) {
        int m = (int)word1.size();
        int n = (int)word2.size();
        vector<vector<int>> dist(m + 1, vector<int>(n + 1, -1));
        return DP(dist, word1, word2, 0, 0);
    }
};