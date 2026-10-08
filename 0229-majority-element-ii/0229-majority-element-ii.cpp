class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        vector<int> ans;
        for(auto itr : mp){
            if(itr.second > (n / 3)){
                ans.push_back(itr.first);
            }
        }

        return ans;
    }
};