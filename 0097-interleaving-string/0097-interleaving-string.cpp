class Solution {
public:
    int m , n , N;

    bool solve(int i , int j , int k , string& s1, string& s2, string& s3 , vector<vector<vector<int>>>& dp){

        if(i == m && j == n && k == N){
            return true;
        }

        if(k == N){
            return false;
        }

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        bool res = false;

        if(s1[i] == s3[k]){
            res = solve(i + 1 , j , k + 1 , s1 , s2 , s3 , dp);
        }

        if(res == true){
            return true;
        }

        if(s2[j] == s3[k]){
            res = solve(i , j + 1 , k + 1 , s1 , s2 , s3 , dp);
        }

        return dp[i][j][k] = res;
    }

    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();

        if(m + n != N){
            return false;
        }

        vector<vector<vector<int>>> dp(m + 1 , vector<vector<int>>(n + 1 , vector<int>(N + 1, -1)));

        return solve(0 , 0 , 0 , s1 , s2 , s3 , dp);
    }
};