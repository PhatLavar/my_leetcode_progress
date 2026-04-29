#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;

    long long DP_full(vector<int>& full, vector<int>& partial, int n) {
        if (n <= 2) return full[n] = n;
        if (full[n] != -1) return full[n];

        return full[n] = (
            DP_full(full, partial, n - 1) + 
            DP_full(full, partial, n - 2) + 
            2 * DP_partial(full, partial, n - 1)
        ) % MOD;
    }

    long long DP_partial(vector<int>& full, vector<int>& partial, int n) {
        if (n == 0 || n == 1) return partial[n] = 0;
        if (n == 2) return partial[n] = 1;
        if (partial[n] != -1) return partial[n];

        return partial[n] = (
            DP_partial(full, partial, n - 1) +
            DP_full(full, partial, n - 2)
        ) % MOD;
    }

public:
    int numTilings(int n) {
        vector<int> full(n + 1, -1);
        vector<int> partial(n + 1, -1);
        return (int)DP_full(full, partial, n);
    }
};