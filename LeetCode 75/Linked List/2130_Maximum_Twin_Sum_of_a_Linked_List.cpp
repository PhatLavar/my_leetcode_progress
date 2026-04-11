#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        if (head && head->next && !head->next->next) 
            return head->val + head->next->val;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        int maxTwin = head->val + prev->val;
        ListNode* half1 = head->next;
        ListNode* half2 = prev->next;
        while (half2) {
            int sumTwin = half1->val + half2->val;
            if (sumTwin > maxTwin) maxTwin = sumTwin;
            half1 = half1->next;
            half2 = half2->next;
        }

        return maxTwin;
    }
};