class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastSeen(256, -1);
        int ans = 0;
        int l = 0 , r = 0;
        int n = s.length();

        while(r < n){
            
            if(lastSeen[s[r]] >= l){
                l = lastSeen[s[r]] + 1;
            }

            int len = r - l + 1;
            ans = max(ans , len);
            
            lastSeen[s[r]] = r;
            r++;
        }

        return ans;   
    }
};