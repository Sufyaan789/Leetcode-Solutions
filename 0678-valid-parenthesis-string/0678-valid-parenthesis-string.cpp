class Solution {
public:
    
    bool solve(int ind, int open, string& s, vector<vector<int>>& dp){

        // base case
        if(ind == s.length()){
            return (open == 0);
        }

        if(dp[ind][open] != -1){
            return dp[ind][open];
        }

        bool isValid = false;

        if(s[ind] == '('){
            isValid |= solve(ind + 1, open + 1, s, dp);
        }
        else if(s[ind] == '*'){
            // '*' acts as '('
            isValid |= solve(ind + 1, open + 1, s, dp);

            // '*' acts as empty
            isValid |= solve(ind + 1, open, s, dp);

            // '*' acts as ')'
            if(open > 0){
                isValid |= solve(ind + 1, open - 1, s, dp);
            }
        }
        else{
            // s[ind] == ')'
            if(open > 0){
                isValid |= solve(ind + 1, open - 1, s, dp);
            }
        }

        return dp[ind][open] = isValid;
    }

    bool checkValidString(string s) {
        int n = s.length();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(0, 0, s, dp);
    }
};