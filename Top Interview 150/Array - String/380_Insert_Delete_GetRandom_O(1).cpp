#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> nums_map;

public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (nums_map.count(val)) return false;
        nums_map[val] = (int)nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!nums_map.count(val)) return false;

        int val_idx = nums_map[val];
        int last_num = nums.back();

        nums[val_idx] = last_num;
        nums_map[last_num] = val_idx;

        nums.pop_back();
        nums_map.erase(val);
        return true; 
    }
    
    int getRandom() {
        int random_idx = rand() % (int)nums.size();
        return nums[random_idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */