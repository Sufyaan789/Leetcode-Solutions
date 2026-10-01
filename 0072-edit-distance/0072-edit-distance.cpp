class Solution {
public:

    int solve(int i , int j , string& word1 , string& word2 , vector<vector<int>>& dp){

        //base case
        if(i == word1.length()){
            //return number of characters left in word2 from j to word2.length()
            return word2.length() - j;
        }

        if(j == word2.length()){
            //return number of characters left in word1 from i to word1.length()
            return word1.length() - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(word1[i] == word2[j]){
            return dp[i][j] = solve(i + 1 , j + 1 , word1 , word2 , dp);
        }
        else{
            return dp[i][j] = 1 + min({ solve(i , j + 1 , word1 , word2 , dp) , solve(i + 1 , j , word1 , word2 , dp) , 
                            solve(i + 1 , j + 1 , word1 , word2 , dp) });
        }
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>>dp(m , vector<int>(n , -1));
        return solve(0 , 0, word1 , word2 , dp);
    }
};