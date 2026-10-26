class Solution {
public:
    int m, n;
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, 1, -1};

    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& vis,
             long long& sum) {

        if (r >= m || r < 0 || c >= n || c < 0) {
            return;
        }

        if (grid[r][c] == 0 || vis[r][c]) {
            return;
        }

        vis[r][c] = true;
        sum += grid[r][c];

        for (int k = 0; k < 4; k++) {
            int x_i = r + x[k];
            int y_i = c + y[k];

            dfs(grid, x_i, y_i, vis, sum);
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] != 0 && !vis[i][j]) {
                    long long sum = 0;
                    dfs(grid, i, j, vis, sum);
                    if (sum % k == 0) ans++;
                }
            }
        }

        return ans;
    }
};