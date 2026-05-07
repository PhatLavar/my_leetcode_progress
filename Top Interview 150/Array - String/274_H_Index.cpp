#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int i = 0;

        for (; i < (int)citations.size(); i++) {
            if (citations[i] >= i + 1) continue;
            break;
        }

        return i;
    }
};