#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int city, vector<vector<int>>& isConnected, int size, vector<bool>& visited) {
        visited[city] = true;

        for (int i = 0; i < size; i++) {
            if (isConnected[city][i] && !visited[i]) {
                dfs(i, isConnected, size, visited);
            }
        }  
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = (int)isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, n, visited);
                provinces++;
            }
        }

        return provinces;
    }
};