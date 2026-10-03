class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> res;

        vector<int> mp(26 , -1);
        for(int i = 0; i < n; i++){
            int ind = s[i] - 'a';
            mp[ind] = i;
        }


        int i = 0;
        while(i < n){
            int end = mp[s[i] - 'a'];
            int j = i;

            while(j < end){
                end = max(end , mp[s[j] - 'a']);
                j++;
            }
            res.push_back(j - i + 1);
            i = j + 1;
        }

        return res;
    }
};