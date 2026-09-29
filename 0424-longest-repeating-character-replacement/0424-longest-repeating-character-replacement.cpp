class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char , int> mp;

        int l = 0;
        int maxfreq = 0;
        int ans = 0;
        int n = s.length();

        for(int r = 0; r < n; r++){

            mp[s[r]]++;
            maxfreq = max(maxfreq , mp[s[r]]);

            while( (r - l + 1) - maxfreq > k){
                mp[s[l]]--;
                l++;
            }

            ans = max(ans , r - l + 1);
        }

        return ans;
    }
};
