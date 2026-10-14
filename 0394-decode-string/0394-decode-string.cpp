class Solution {
public:
    string decodeString(string s) {
        vector<string> st;

        for (char c : s) {
            
            if (c != ']') {
                st.push_back(string(1, c));
            }
            else {
                // Build the string inside the brackets
                string curr = "";

                while (st.back() != "[") {
                    curr = st.back() + curr;
                    st.pop_back();
                }

                st.pop_back(); // Remove '['

                // Get the repetition count
                string num = "";

                while (!st.empty() && isdigit(st.back()[0])) {
                    num = st.back() + num;
                    st.pop_back();
                }

                int k = stoi(num);

                // Repeat the current string k times
                string temp = "";
                for (int i = 0; i < k; i++) {
                    temp += curr;
                }

                st.push_back(temp);
            }
        }

        // Combine all remaining parts
        string ans = "";
        for (string part : st) {
            ans += part;
        }

        return ans;
    }
};
