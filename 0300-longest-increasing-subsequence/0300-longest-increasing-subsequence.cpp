#include <bits/stdc++.h>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                //we use -temp.begin() over here as lower_bound gives us an iterator and to convert it into
                // index we substract -temp.begin()
                int ind = lower_bound(temp.begin() , temp.end() , nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        return temp.size();
    }
};