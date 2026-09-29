class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.length();
        int m = s2.length();

        if(n > m){
            return false;
        }

        vector<int> freqs1(26 , 0);
        vector<int> freqs2(26 , 0);

        for(char ch : s1){
            freqs1[ch - 'a']++;
        }

        int i = 0 , j = 0;

        while(j < m){
            freqs2[s2[j] - 'a']++;

            if(j - i + 1 > n){
                freqs2[s2[i] - 'a']--;
                i++;
            }

            if(freqs1 == freqs2){
                return true;
            }
            j++;
        }

        return false;
    }
};