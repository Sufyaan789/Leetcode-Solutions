class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        string res = "";
        int mx = max(n , m);

        for(int i = 0; i < mx; i++){

            if(i < n && i < m){
                res.push_back(word1[i]);
                res.push_back(word2[i]);
            }

            if(i >= n){
                res.push_back(word2[i]);
            }

            if(i >= m){
                res.push_back(word1[i]);
            }
        }

        return res;
    }
};