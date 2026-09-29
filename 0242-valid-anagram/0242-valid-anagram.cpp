class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        array<int , 26> freqs = {};
        array<int , 26> freqt = {};

        for(char c : s){
            freqs[c - 'a']++;
        }
        for(char c : t){
            freqt[c - 'a']++;
        }

        if(freqs == freqt)
            return true;
        
        return false;
    }
};