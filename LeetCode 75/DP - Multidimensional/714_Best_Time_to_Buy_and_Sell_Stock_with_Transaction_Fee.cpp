#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int DP(vector<vector<int>>& dp, vector<int>& prices, int n, int holding, int fee) {
        if (n == 0) {
            if (holding == 0) return dp[0][0] = 0;
            if (holding == 1) return dp[0][1] = -prices[0];
        }

        if (dp[n][holding] != 1e5) return dp[n][holding];

        // still not holding --> keep not holding or just sold it! 
        if (holding == 0) return dp[n][0] = max(
            DP(dp, prices, n - 1, 1, fee) + prices[n] - fee,
            DP(dp, prices, n - 1, 0, fee)
        );
        
        // still holding --> keep holding or just bought it! 
        else if (holding == 1) return dp[n][1] = max(
            DP(dp, prices, n - 1, 0, fee) - prices[n],
            DP(dp, prices, n - 1, 1, fee)
        );
        
        return -1;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = (int)prices.size();
        vector<vector<int>> stock(n, vector<int>(2, 1e5));
        return DP(stock, prices, n - 1, 0, fee);
    }
};