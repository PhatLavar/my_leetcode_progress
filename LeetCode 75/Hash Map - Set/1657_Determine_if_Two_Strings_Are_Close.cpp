#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<bool> contains1(26, 0), contains2(26, 0);
        vector<int> freq1(26, 0), freq2(26, 0);

        for (char c : word1) {
            contains1[c - 'a'] = true;
            freq1[c - 'a']++;
        }

        for (char c : word2) {
            contains2[c - 'a'] = true;
            freq2[c - 'a']++;
        }

        if (contains1 != contains2) return false;
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};