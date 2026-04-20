#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    double dfs(const string& curr, const string& end, unordered_map<string, unordered_map<string, double>> divGraph, unordered_set<string> visited) {
        if (curr == end) return 1.0;
        visited.insert(curr);

        for (auto& [neighbor, value] : divGraph[curr]) {
            if (visited.count(neighbor)) continue;

            double division = dfs(neighbor, end, divGraph, visited);
            if (division != -1.0) return division * value;
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> divGraph((int)values.size());
        for (int i = 0; i < (int)values.size(); i++) {
            string startChar = equations[i][0];
            string endChar = equations[i][1];

            divGraph[startChar][endChar] = values[i];
            divGraph[endChar][startChar] = 1.0 / values[i];
        }
        
        vector<double> divisions;

        for (auto& query : queries) {
            string start = query[0];
            string end = query[1];

            if (divGraph.find(start) == divGraph.end() || divGraph.find(end) == divGraph.end())
                divisions.push_back(-1.0);

            else if (start == end) divisions.push_back(1.0);
            
            else {
                unordered_set<string> visited;
                divisions.push_back(dfs(start, end, divGraph, visited));
            } 
        }
        
        return divisions;
    }
};