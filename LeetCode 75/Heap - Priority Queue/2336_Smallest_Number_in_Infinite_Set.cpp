#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
private:
    unordered_set<int> infSet;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int currNum;

public:
    SmallestInfiniteSet() {
        this->currNum = 1;
    }
    
    int popSmallest() {
        if (minHeap.empty()) return currNum++;

        int smallest = minHeap.top();
        minHeap.pop();
        infSet.erase(smallest);

        return smallest;
    }
    
    void addBack(int num) {
        if (num < currNum && infSet.find(num) == infSet.end()) {
            minHeap.push(num);
            infSet.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */