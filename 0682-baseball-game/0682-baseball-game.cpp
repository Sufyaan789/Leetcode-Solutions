class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();

        stack<int> st;
        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (operations[i] == "C") {
                st.pop();
            }
            else if (operations[i] == "D") {
                int ch1 = st.top();
                st.push(2 * ch1);
            }
            else if (operations[i] == "+") {
                int ch2 = st.top();
                st.pop();

                int ch3 = st.top();

                st.push(ch2);
                st.push(ch2 + ch3);
            }
            else {
                st.push(stoi(operations[i]));
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};