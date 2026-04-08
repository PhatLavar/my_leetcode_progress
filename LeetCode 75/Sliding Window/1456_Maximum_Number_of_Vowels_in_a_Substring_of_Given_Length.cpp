#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char c) {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
    }

public:
    int maxVowels(string s, int k) {
        int maxCount = 0;
        for (int i = 0; i < k; i++) {
            maxCount += isVowel(s[i]);
        }

        int count = maxCount;
        for (int i = k; i < (int)s.length(); i++) {
            count = count + isVowel(s[i]) - isVowel(s[i - k]);
            if (count > maxCount) maxCount = count;
        }

        return maxCount;
    }
};