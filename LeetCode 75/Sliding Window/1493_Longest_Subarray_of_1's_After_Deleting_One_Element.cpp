#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int longest = 0;
        int zeroes = 0;
        int right = 0, left = 0;

        for (; right < (int)nums.size(); right++) {
            if (nums[right] == 0) zeroes++;

            while (zeroes > 1) {
                if (nums[left] == 0) zeroes--;
                left++;
            }

            if (right - left > longest) longest = right - left;
        }

        return longest;
    }
};