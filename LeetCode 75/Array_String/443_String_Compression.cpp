#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int size = (int)chars.size();
        if (size == 1) return 1;
        int charCount = 1;
        int writeIndex = 0;

        for (int i = 1; i < size; i++) {
            if (chars[i] == chars[i - 1]) {
                charCount++;
            } else {
                chars[writeIndex++] = chars[i - 1];
                if (charCount > 1) {
                    string numStr = to_string(charCount);
                    for (char c : numStr) chars[writeIndex++] = c;
                    charCount = 1;
                } 
            }
        }

        chars[writeIndex++] = chars[size - 1];
        if (charCount > 1) {
            string numStr = to_string(charCount);
            for (char c : numStr) chars[writeIndex++] = c;
        } 

        return writeIndex;
    }
};