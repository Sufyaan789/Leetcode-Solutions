class Solution {
public:

    bool solve(int i , int j , string& s, string& p , vector<vector<int>>& dp){

        if(j == p.length()){
            return i == s.length();
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        bool first_char_matched = false;

        if( i < s.length() && (p[j] == s[i] || p[j] == '.') ){
            first_char_matched = true;
        }

        if(p[j + 1] == '*'){
            bool not_take = solve(i , j + 2 , s , p , dp);
            bool take = first_char_matched && solve(i + 1 , j , s , p , dp);

            return dp[i][j] = not_take || take;
        }

        return dp[i][j] = first_char_matched && solve(i + 1 , j + 1 , s , p , dp);
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
        return solve(0 , 0 , s , p , dp); 
    }
};