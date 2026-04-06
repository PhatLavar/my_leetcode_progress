#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isValid(string str1, string str2) {
        return str1 + str2 == str2 + str1;
    }

    int gcdOfNums(int num1, int num2) {
        if (num2 == 0) return num1;
        return gcdOfNums(num2, num1 % num2);
    }

public:
    string gcdOfStrings(string str1, string str2) {
        string output = isValid(str1, str2) ? str1.substr(0, gcdOfNums(str1.length(), str2.length())) : "";
        return output;
    }
};