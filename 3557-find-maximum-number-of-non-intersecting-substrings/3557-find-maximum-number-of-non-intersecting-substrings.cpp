class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.length();
        vector<int> arr(26 , -1);
        int ans = 0;

        for(int i = 0; i < n; i++){
            int ind = word[i] - 'a';
            if(arr[ind] != -1 && (i - arr[ind] + 1) >= 4){
                ans++;
                for(int j = 0; j < 26; j++){
                    arr[j] = -1;
                }
            }
            else{
                if(arr[ind] == -1){
                    arr[ind] = i;
                }
            }
        }

        return ans;
    }
};