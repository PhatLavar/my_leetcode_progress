#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = (int)potions.size();

        int n = (int)spells.size();
        vector<int> output(n);

        for (int i = 0; i < n; i++) {
            int spell = spells[i];
            int left = 0; int right = m - 1;
            int goodMid = m;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if ((long long)spell * potions[mid] >= success) {
                    goodMid = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            output[i] = m - goodMid;
        }

        return output;
    }
};