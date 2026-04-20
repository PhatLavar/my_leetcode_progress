#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = (int)maze.size(); int n = (int)maze[0].size();
        int step = 0;

        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[entrance[0]][entrance[1]] = true;

        queue<pair<int, int>> possibleStep;
        possibleStep.push({entrance[0], entrance[1]});

        while (!possibleStep.empty()) {
            int size = (int)possibleStep.size();

            for (int i = 0; i < size; i++) {
                auto [r, c] = possibleStep.front();
                possibleStep.pop();

                bool isExit = (r == 0) || (r == m - 1) || (c == 0) || (c == n - 1);
                bool isEntrance = (r == entrance[0]) && (c == entrance[1]);

                if (isExit && !isEntrance) return step;

                for (auto& dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    bool validRow = (nr >= 0) && (nr < m);
                    bool validCol = (nc >= 0) && (nc < n);

                    if (validRow && validCol && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        if (maze[nr][nc] != '+') possibleStep.push({nr, nc});
                        else continue;
                    }
                }
            }

            step++;
        }
        
        return -1;
    }
};