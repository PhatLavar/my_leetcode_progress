#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string currStr = "";
        int currNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                currNum = currNum*10 + (c - '0');
            } else if (c == '[') {
                numStack.push(currNum);
                strStack.push(currStr);
                currStr = "";
                currNum = 0;
            } else if (c == ']') {
                int repeat = numStack.top();
                numStack.pop();
                string temp = "";

                while (repeat > 0) {
                    temp += currStr;
                    repeat--;
                }

                currStr = strStack.top() + temp;
                strStack.pop();
            } else {
                currStr += c;
            }
        }

        return currStr;
    }
};