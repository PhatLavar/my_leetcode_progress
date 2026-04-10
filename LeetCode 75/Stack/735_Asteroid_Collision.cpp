#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int n = (int)asteroids.size();

        for (int asteroid : asteroids) {
            bool exploded = false;

            if (asteroid > 0) {
                st.push_back(asteroid);
            } else {
                while (!st.empty() && st.back() > 0 && !exploded) {
                    if (-asteroid > st.back()) {
                        st.pop_back();
                    } else if (-asteroid == st.back()) {
                        st.pop_back();
                        exploded = true;
                        break;
                    } else {
                        exploded = true;
                        break;
                    }
                }

                if (!exploded) st.push_back(asteroid);
            }
        }

        return st;
    }
};