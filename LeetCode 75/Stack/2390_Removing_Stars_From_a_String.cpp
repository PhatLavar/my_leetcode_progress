#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string output = "";
        for (char c : s) {
            if (c == '*') {
                if (!output.empty()) output.pop_back();
            } else {
                output.push_back(c);
            }
        }

        return output;
    }
};