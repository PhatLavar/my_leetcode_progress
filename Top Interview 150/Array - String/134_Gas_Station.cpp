#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currGas = 0;
        int currCost = 0;
        int n = (int)gas.size();

        for (int i = 0; i < n; i++) {
            currGas += gas[i];
            currCost += cost[i];
        }

        if (currGas < currCost) return -1;

        int start = 0;
        currGas = 0;
        for (int i = 0; i < n; i++) {
            currGas += gas[i] - cost[i];
            if (currGas < 0) {
                currGas = 0;
                start = i + 1;
            }
        }

        return start;
    }
};