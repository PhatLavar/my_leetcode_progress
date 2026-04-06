#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = (int)candies.size();
        vector<bool> output(n);
        int maxCandies = candies[0];

        for (int i = 1; i < n; i++) {
            if (candies[i] > maxCandies) maxCandies = candies[i];
            else continue;
        }

        for (int i = 0; i < n; i++) {
            output[i] = candies[i] >= maxCandies - extraCandies;
        }

        return output;
    }
};