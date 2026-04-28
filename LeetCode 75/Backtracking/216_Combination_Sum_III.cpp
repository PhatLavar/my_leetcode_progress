#include <bits/stdc++.h>
using namespace std;

class Solution {
    void backtrack(
        int start,
        int sum,
        int k,
        int n,
        vector<int>& path,
        vector<vector<int>>& result)
    {
        if ((int)path.size() == k) {
            if (sum == n) result.push_back(path);
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (sum + i > n) break;
            path.push_back(i);
            backtrack(i + 1, sum + i, k, n, path, result);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> result;
        backtrack(1, 0, k, n, path, result);
        return result;
    }
};