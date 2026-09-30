class Solution {
    int S;
public:
   
    int solve(vector<int>& nums , int target , int i , int currSum , vector<vector<int>>& dp){

        if(i == nums.size()){
            return target == currSum;
        }

        if(dp[i][currSum + S] != -1){
            return dp[i][currSum + S];
        }

        int plus = solve(nums , target , i + 1 , currSum + nums[i] , dp);
        int minus = solve(nums , target , i + 1 , currSum - nums[i] , dp);

        return dp[i][currSum + S] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        S = accumulate(begin(nums) , end(nums) , 0);
        vector<vector<int>> dp(n + 1 , vector<int>(2 * S + 1 , -1));

        return solve(nums, target , 0 , 0 , dp);
    }
};