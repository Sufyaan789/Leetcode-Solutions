class Solution {
private:

    bool solve(string& s, unordered_set<string>& st, vector<int>& dp, int ind) {

        int n = s.length();

        // base case
        if(ind == n) {
            return true;
        }

        if(st.find(s.substr(ind, n - ind)) != st.end()) {
            return true;
        }

        if(dp[ind] != -1) {
            return dp[ind];
        }

        for(int l = 1; l <= n; l++) {

            string temp = s.substr(ind, l);

            if(st.find(temp) != st.end() && solve(s, st, dp, ind + l)) {
                return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.length();

        unordered_set<string> st;
        vector<int> dp(n, -1);

        for(string& word : wordDict) {
            st.insert(word);
        }

        return solve(s, st, dp, 0);
    }
};