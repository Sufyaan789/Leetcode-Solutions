class Solution {
    int m , n;
    long long int mod = 1e9 + 7;
    //dir = 0 --> prev move was right
    //dir = 1 --> prev move was down 
public:
    int f(int i , int j , int dir , vector<vector<int>>& grid , vector<vector<vector<int>>>& dp){

        //base cases
        if(i >= m || j >= n){
            return 0;
        }
        if(i == m - 1 && j == n - 1){
            return 1;
        }

        if(dp[i][j][dir] != -1){
            return dp[i][j][dir];
        }

        if(grid[i][j] == 1){
            if(dir == 0){
                dp[i][j][dir] = f(i+1 , j , 1 , grid , dp);
            }
            else{
                dp[i][j][dir] = f(i , j+1 , 0 , grid , dp);
            }
        }
        else{
            long long down = f(i+1, j, 1, grid, dp);
            long long right = f(i, j+1, 0, grid, dp);

            dp[i][j][dir] = (down + right) % mod;
        }

        return dp[i][j][dir];
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));

        return f(0 , 0 , 0 , grid , dp);
    }
};