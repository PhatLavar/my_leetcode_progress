#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = (int)nums1.size();

        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({nums2[i], nums1[i]});
        }
        sort(pairs.rbegin(), pairs.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long score = 0;
        long long max_score = 0;

        for (auto& [n2, n1] : pairs) {
            score += n1;
            minHeap.push(n1);

            if ((int)minHeap.size() > k) {
                score -= minHeap.top();
                minHeap.pop();
            }

            if ((int)minHeap.size() == k) {
                max_score = max(max_score, score * n2);
            }
        }

        return max_score;
    }
};