#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string word;

        while (ss >> word) words.push_back(word);
        string output = "";

        for (int i = (int)words.size() - 1; i >= 0; i--) {
            output += words[i];
            if (i != 0) output += " ";
        }

        return output;
    }
};