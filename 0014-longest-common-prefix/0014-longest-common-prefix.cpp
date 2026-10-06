class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin() , strs.end());
        string ans = "";
        int i = 0 , n = strs.size();

        while(i < strs[0].length()){

            if(strs[0][i] == strs[n - 1][i]){
                ans += strs[0][i];
            }
            else{
                break;
            }
            i++;
        }

        return ans;
    }
};