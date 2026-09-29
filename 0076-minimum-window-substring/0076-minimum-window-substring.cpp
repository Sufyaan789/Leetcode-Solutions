class Solution {
public:
    string minWindow(string s, string t) {
        /* freq stores the number of occurances of each of the characters in t
        windows stores the no. of occurances of each character in our curr window */ 
        int freq[128] = {0};
        int window[128] = {0};
        
        for (char c : t)
            freq[c]++;

        /* the req variable stores how many diff characters does t require 
        eg: t = ABCC , req = 3 */
        int req = 0;
        for(int i = 0; i < 128; i++){
            if(freq[i] > 0)
                req++;
        }

        /* left is our initial pointer at 0 , ans is final ans , formed stores how many unique characters are present 
        in our current windows that satisfy string t , ansSt stores the starting index of best answer from our current 
        window */
        int left = 0;
        int ans = 1e9;
        int formed = 0;
        int ansSt = 0;

        for (int r = 0; r < s.length(); r++) {

            char c = s[r];
            window[c]++;

            /* this condition signifies that the char c is present in t and also the second cond says that we should only
            consider the repeating characters freq[c] number of times 
            eg: s = AAAABC , t = ABC then we only consider the first A in s  */
            if (freq[c] > 0 && window[c] == freq[c]) {
                formed++;
            }

            /* this while condition says as long as the window has all the elements present in t */
            while (formed == req) {

                if (r - left + 1 < ans){
                    ans = r - left + 1;
                    ansSt = left;
                }

                /* now we start to shrink from the left as we have already encountered a valid window */
                char rv = s[left];
                window[rv]--;

                /* in the first testcase the first valid window will be ADOBEC ,then rv = A and windows[rv] = 0 
                and since freq[rv] = 1 and window[rv] < freq[rv] (0 < 1) , then formed = 3 -> 2 and left = 1 and
                we start to form a new window */
                if (freq[rv] > 0 && window[rv] < freq[rv]) {
                    formed--;
                }
                left++;
            }
        }

        if(ans == 1e9){
            return "";
        }

        return s.substr(ansSt , ans);
    }
};
