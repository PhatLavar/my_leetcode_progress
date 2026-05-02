#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = (int)temperatures.size();
        stack<int> temp;
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {  
            while (!temp.empty() && temperatures[temp.top()] < temperatures[i]) {
                result[temp.top()] = i - temp.top();
                temp.pop();
            }
            temp.push(i);
        }

        return result;
    }
};