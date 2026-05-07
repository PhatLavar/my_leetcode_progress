#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0;
        int majority = 0;

        // If the elements really appears more than ⌊n / 2⌋,
        // majority cant be 0
        for (int num : nums) {
            if (majority == 0) result = num;
            majority += (num == result) ? 1 : -1;
        }

        return result;
    }
};