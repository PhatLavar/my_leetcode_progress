#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int length1 = word1.length(), length2 = word2.length();
        int index1 = 0, index2 = 0;
        string output = "";

        while (index1 < length1 || index2 < length2) {
            if (index1 < length1)
                output.push_back(word1[index1++]);
            if (index2 < length2)
                output.push_back(word2[index2++]);
        }

        return output;
    }
};