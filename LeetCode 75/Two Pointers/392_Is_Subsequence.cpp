#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIdx = 0, tIdx = 0;

        while (tIdx < (int)t.length()) {
            if (t[tIdx] == s[sIdx]) sIdx++;
            tIdx++;
        }

        return sIdx == (int)s.length();
    }
};