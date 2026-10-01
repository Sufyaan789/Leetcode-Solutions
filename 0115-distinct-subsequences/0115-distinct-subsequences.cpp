class Solution {
public:

    int solve(int i , int j , int m , int n , string& s , string& t , vector<vector<int>>& dp){

        //base cases
        if(j == n){
            return 1;
        }

        if(i == m){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] != t[j]){
            return dp[i][j] = solve(i + 1 , j , m , n , s , t , dp);
        }

        return dp[i][j] = solve(i + 1 , j + 1 , m , n , s , t , dp) + solve(i + 1 , j , m , n , s, t , dp);
    }

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solve(0 , 0 , m , n , s , t , dp);
    }
};