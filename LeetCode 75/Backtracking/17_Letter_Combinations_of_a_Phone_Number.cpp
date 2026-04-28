#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> phoneChars = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno", "pqrs",
        "tuv", "wxyz"
    };

    void backtrack(
        int index,
        string& digits,
        vector<string>& phoneChars,
        string& path,
        vector<string>& result) 
    {
        if (index == (int)digits.length()) {
            result.push_back(path);
            return;
        }

        string letters = phoneChars[digits[index] - '0'];

        for (char letter : letters) {
            path.push_back(letter);
            backtrack(index + 1, digits, phoneChars, path, result);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string path = "";
        backtrack(0, digits, phoneChars, path, result);
        return result;
    }
};