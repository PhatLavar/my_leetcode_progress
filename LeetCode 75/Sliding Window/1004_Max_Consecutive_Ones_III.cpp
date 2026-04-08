#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int longest = 0;
        int zeroes = 0;
        int right = 0, left = 0;

        for (; right < (int)nums.size(); right++) {
            if (nums[right] == 0) zeroes++;
            while (zeroes > k) {
                if (nums[left] == 0) zeroes--;
                left++;
            }

            if (right - left + 1 > longest) longest = right - left + 1;
        }

        return longest;
    }
};