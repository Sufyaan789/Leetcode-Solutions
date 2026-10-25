class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            }
            else {
                bool alive = true;

                while (!st.empty() && st.top() > 0) {
                    // the case where negative asteroid size is bigger , so we keep on removing the last element from the stack
                    if (st.top() < -asteroids[i]) {
                        st.pop();
                    }
                    //the case where both are equal , both will be destroyed
                    else if (st.top() == -asteroids[i]) {
                        st.pop();
                        alive = false;
                        break;
                    }
                    // the case where positive asteroid size is bigger , we ignore the negative asteroid 
                    else {
                        alive = false;
                        break;
                    }
                }

                if (alive) {
                    st.push(asteroids[i]);
                }
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};