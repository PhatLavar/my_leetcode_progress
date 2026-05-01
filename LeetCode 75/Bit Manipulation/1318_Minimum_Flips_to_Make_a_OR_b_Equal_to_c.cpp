#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        while(a > 0 || b > 0 || c > 0) {
            int abit = a & 1;
            int bbit = b & 1;
            int cbit = c & 1;

            if (cbit == 0) {
                if (abit == 1) flips++;
                if (bbit == 1) flips++;
            } else {
                if (abit == 0 && bbit == 0) flips++;
            }

            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }

        return flips;
    }
};