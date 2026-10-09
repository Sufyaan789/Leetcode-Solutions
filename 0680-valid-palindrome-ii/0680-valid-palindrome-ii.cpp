class Solution {
public:

    bool solve(string& s , int l , int r){

        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int n = s.length();
        int l = 0;
        int r = n - 1;

        while(l < r){
            if(s[l] != s[r]){
                return solve(s , l + 1 , r) || solve(s , l , r - 1);
            }

            l++;
            r--;
        }

        return true;
    }
};