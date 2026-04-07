#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int size = (int)nums.size();
        if (size == 1) return;

        while (left < size && nums[left] != 0) left++;

        for (int right = left + 1; right < size; right++) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};