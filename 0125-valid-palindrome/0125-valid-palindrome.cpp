class Solution {
private:
    bool isValid(char s) {
        if ((s >= 'A' && s <= 'Z') || 
            (s >= 'a' && s <= 'z') ||
            (s >= '0' && s <= '9')) {
            return true;
        }

        return false;
    }

    char toLowerCase(char ch) {
        if ((ch >= 'a' && ch <= 'z') || 
            (ch >= '0' && ch <= '9')) {
            return ch;
        } 
        else {
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool checkPalindrome(string a) {
        int s = 0;
        int e = a.length() - 1;

        while (s <= e) {
            if (a[s] != a[e]) {
                return false;
            }

            s++;
            e--;
        }

        return true;
    }

public:
    bool isPalindrome(string s) {

        string temp = "";

        for (int i = 0; i < s.length(); i++) {

            if (isValid(s[i])) {
                temp.push_back(s[i]);
            }
        }

        for (int j = 0; j < temp.length(); j++) {
            temp[j] = toLowerCase(temp[j]);
        }

        return checkPalindrome(temp);
    }
};

