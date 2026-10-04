class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        sort(intervals.begin() , intervals.end());
        int n = intervals.size();

        int sInt = intervals[0][0];
        int eInt = intervals[0][1];

        for(int i = 1; i < n; i++){

            if(eInt >= intervals[i][0]){
                sInt = min(sInt , intervals[i][0]);
                eInt = max(eInt , intervals[i][1]);
            }
            else{
                ans.push_back({sInt , eInt});
                sInt = intervals[i][0];
                eInt = intervals[i][1];
            }
        }
        
        ans.push_back({sInt , eInt});
        return ans;
    }
};
