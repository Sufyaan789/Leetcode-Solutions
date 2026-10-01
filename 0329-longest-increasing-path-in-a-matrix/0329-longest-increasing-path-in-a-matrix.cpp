class Solution {
    int m;
    int n;

    int x[4] = {-1 , 1 , 0 , 0};
    int y[4] = {0 , 0 , 1 , -1};
public:

    bool isValid(int i , int j , int m , int n){

        if(i < 0 || i >= m || j < 0 || j >= n){
            return false;
        }

        return true;
    }

    int solve(int i , int j , vector<vector<int>>& matrix , int m , int n , vector<vector<int>>& dp){ 

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        for(int k = 0; k < 4; k++){
            int r = i + x[k];
            int c = j + y[k];

            if(isValid(r , c , m , n) && matrix[i][j] < matrix[r][c]){
                ans = max(ans , solve(r , c , matrix , m , n , dp));
            } 
        }

        return dp[i][j] = 1 + ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> dp(m , vector<int>(n , -1));

        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                cnt = max(cnt , solve(i , j , matrix , m , n , dp));
            }
        }

        return cnt;
    }
};