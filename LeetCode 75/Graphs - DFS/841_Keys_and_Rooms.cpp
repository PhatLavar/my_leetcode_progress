#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = (int)rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;

        stack<int> roomStack;
        roomStack.push(0);

        while (!roomStack.empty()) {
            int current_room = roomStack.top();
            roomStack.pop();

            for (int key : rooms[current_room]) {
                if (!visited[key]) {
                    visited[key] = true;
                    roomStack.push(key);
                }
            }
        }

        for (bool visitedRoom : visited) {
            if (!visitedRoom) return false;
        }

        return true;
    }
};