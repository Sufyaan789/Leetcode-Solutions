class Solution {
public:

    bool solve(vector<int>& nums , int ind , int x , vector<vector<int>>& dp){
        int n = nums.size();

        if(x == 0){
            return true;
        }

        if(ind >= n){
            return false;
        }

        if(dp[ind][x] != -1){
            return dp[ind][x];
        }

        bool notTake = solve(nums , ind + 1 , x , dp);
        bool take = false;

        if(x >= nums[ind]){
            take = solve(nums , ind + 1 , x - nums[ind] , dp);
        }

        return dp[ind][x] = notTake || take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 != 0){
            return false;
        }

        int x = sum / 2;
        vector<vector<int>> dp(n + 1 , vector<int>(sum + 1 , -1));

        return solve(nums , 0 , x , dp);
    }
};