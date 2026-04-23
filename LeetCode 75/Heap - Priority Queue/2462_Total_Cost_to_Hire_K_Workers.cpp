#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = (int)costs.size();
        int i = 0; int j = n - 1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leftHeap;
        for (int cnt = 0; cnt < candidates && i <= j; cnt++)
            leftHeap.push({costs[i], i++});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rightHeap;
        for (int cnt = 0; cnt < candidates && j >= i; cnt++)
            rightHeap.push({costs[j], j--});

        long long output = 0;
        for (int hired = 0; hired < k; hired++) {
            if (rightHeap.empty() || (!leftHeap.empty() && leftHeap.top() <= rightHeap.top())) {
                auto [cost, idx] = leftHeap.top();
                leftHeap.pop();
                output += cost;
                if (i <= j) leftHeap.push({costs[i], i++});
            } 
            
            else {
                auto [cost, idx] = rightHeap.top();
                rightHeap.pop();
                output += cost;
                if (j >= i) rightHeap.push({costs[j], j--});
            }
        }

        return output;
    }
};