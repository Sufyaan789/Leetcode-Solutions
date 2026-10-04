class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });

        int cnt = 0;
        int end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(end <= intervals[i][0]){
                end = intervals[i][1];
            }
            else{
                cnt++;
            }
        }

        return cnt;
    }
};