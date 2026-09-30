class Solution {
    private:
    int f(int ind , bool buy , vector<int>& prices , vector<vector<int>>& dp){

        int profit = 0;
        int n = prices.size();

        if(ind >= n){
            return 0;
        }

        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }

        if(buy){
            profit = max(f(ind + 1 , 0 , prices , dp) - prices[ind] , 0 + f(ind + 1 , 1 , prices , dp));
        }
        else{
            profit = max(f(ind + 2 , 1 , prices , dp) + prices[ind] , 0 + f(ind + 1 , 0 , prices , dp));
        }

        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2 , -1));
        return f(0 , 1 , prices , dp);
    }
};

