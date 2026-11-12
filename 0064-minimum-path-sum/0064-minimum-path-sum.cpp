class Solution {
private:
    int f(int i, int j, vector<vector<int>>& maze, vector<vector<int>>& dp) {
        // base case: out of bounds
        if (i < 0 || j < 0)
            return 1e9;

        // base case: starting cell
        if (i == 0 && j == 0)
            return maze[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = maze[i][j] + f(i - 1, j, maze, dp);
        int left = maze[i][j] + f(i, j - 1, maze, dp);

        return dp[i][j] = min(up, left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) { 
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int> > dp(n , vector<int>(m , -1));

        int ans = f(n-1 , m-1 , grid , dp);
        return ans;
    }
};