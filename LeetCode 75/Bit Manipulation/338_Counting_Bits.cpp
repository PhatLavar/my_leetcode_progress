#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        
        for (int i = 0; i <= n; i++) {
            if (i == 0) ans[i] = 0;
            else if (i == 1 || i == 2) ans[i] = 1;
            else ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};