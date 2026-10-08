class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        unordered_map<int , int> mp;
        int res = 0;
        int curSum = 0;
        mp[0] = 1;

        for(int& num : nums){

            curSum += num;

            if(mp.find(curSum - goal) != mp.end()){
                res += mp[curSum - goal];
            }

            mp[curSum]++;
        }

        return res;
    }
};