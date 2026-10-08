class Solution {
public:

    int solve(int i , vector<int>& prices , bool buy , vector<vector<int>>& dp){
        
        int n = prices.size();
        //base case
        if(i == n){
            return 0;
        }

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int res = solve(i + 1 , prices , buy , dp);
        if(buy){
            res = max(res , prices[i] + solve(i + 1, prices , false , dp));
        }
        else{
            res = max(res , -prices[i] + solve(i + 1, prices , true , dp));
        }
        
        return dp[i][buy] = res;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        //buy --> 0 --> can buy
        //buy --> 1 --> cannot buy
        return solve(0 , prices , 0 , dp);
    }
};