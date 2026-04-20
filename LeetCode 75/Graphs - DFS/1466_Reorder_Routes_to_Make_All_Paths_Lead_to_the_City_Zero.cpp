#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int city, int& reorderCount, vector<vector<pair<int, bool>>>& treeGraph, vector<bool>& visited) {
        visited[city] = true;
        for (auto& neighbor : treeGraph[city]) {
            int nextCity = neighbor.first;
            bool canReach = neighbor.second;

            if (!visited[nextCity]) {
                if (canReach) reorderCount++;
                dfs(nextCity, reorderCount, treeGraph, visited);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> treeGraph(n);
        int reorderCount = 0;
        vector<bool> visited(n, false);

        for (auto& connection : connections) {
            int fromCity = connection[0];
            int toCity = connection[1];

            treeGraph[fromCity].push_back({toCity, true});
            treeGraph[toCity].push_back({fromCity, false});
        }

        dfs(0, reorderCount, treeGraph, visited);
        return reorderCount;
    }
};