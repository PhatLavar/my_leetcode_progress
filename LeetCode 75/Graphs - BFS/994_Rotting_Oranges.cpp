#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int minutes = 0;

        queue<pair<int, int>> rottenOranges;
        int freshCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) rottenOranges.push({i, j});
                if (grid[i][j] == 1) freshCount++;
            }
        }

        if (freshCount == 0) return 0;
        
        while (!rottenOranges.empty() && freshCount) {
            int size = (int)rottenOranges.size();

            for (int i = 0; i < size; i++) {
                auto [r, c] = rottenOranges.front();
                rottenOranges.pop();

                for (auto& dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    bool validRow = (nr >= 0) && (nr < m);
                    bool validCol = (nc >= 0) && (nc < n);

                    if (validRow && validCol && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        rottenOranges.push({nr, nc});
                        freshCount--;
                    }
                }
            }

            minutes++;
        }

        return freshCount == 0 ? minutes : -1;
    }
};