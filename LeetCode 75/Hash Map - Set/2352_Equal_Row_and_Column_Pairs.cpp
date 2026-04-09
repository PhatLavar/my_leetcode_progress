#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int count = 0;
        map<vector<int>, int> rows;

        for (int row = 0; row < n; row++) rows[grid[row]]++;
        for (int col = 0; col < n; col++) {
            vector<int> cols;
            for (int r = 0; r < n; r++) 
                cols.push_back(grid[r][col]);
            count += rows[cols];
        }

        return count;
    }
};