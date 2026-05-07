#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = (int)nums.size() - 1;

        while (i <= j) {
            if (nums[j] == val) {
                j--;
                continue;
            }
            
            if (nums[i] != val) i++;
            else {
                nums[i] = nums[j];
                nums[j] = val;
            }
        }

        return i;
    }
};