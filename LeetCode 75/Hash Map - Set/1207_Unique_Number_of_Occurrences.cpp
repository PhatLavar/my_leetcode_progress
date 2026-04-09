#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> count_vec;
        int count = 1;
        sort(arr.begin(), arr.end());

        for (int i = 1; i < (int)arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                count_vec.push_back(count);
                count = 1;
            }
        }

        count_vec.push_back(count);
        unordered_set<int> count_set(count_vec.begin(), count_vec.end());
        return count_set.size() == count_vec.size();
    }
};