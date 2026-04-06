#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
    }

    string getVowel(string s) {
        string vowelStr = "";
        for (int i = 0; i < s.length(); i++) 
            if (isVowel(s[i])) vowelStr += s[i];
        return vowelStr;
    }

public:
    string reverseVowels(string s) {
        string vowelStr = getVowel(s);
        int index = (int)vowelStr.length() - 1;

        for (char &c : s) 
            if (isVowel(c)) c = vowelStr[index--];
        return s;
    }
};