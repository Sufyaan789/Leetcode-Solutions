class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        int i , j = 0;
        unordered_map<int, int> mp;

        while(j < n){
            mp[nums[j]]++;
            sum += nums[j];

            while(mp[nums[j]] > 1) {
                mp[nums[i]]--;
                sum -= nums[i];
                i++;
            }

            ans = max(ans, sum);
            j++;
        }

        return ans;
    }
};