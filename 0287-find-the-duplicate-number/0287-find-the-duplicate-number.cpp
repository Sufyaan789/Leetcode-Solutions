class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1;
        int r = nums.size() - 1;

        while(l < r){
            int mid = l + (r - l) / 2;
            int cnt = 0;

            for(int num : nums){
                if(num <= mid){
                    cnt++;
                }
            }

            //if count is greater than mid , repetition lies in first half from l -> m
            if(cnt > mid){
                r = mid;
            }
            else{            
            //otherwise the repetition lies in the second part from m + 1 -> r
                l = mid + 1;
            }
        }

        return l;
    }
};