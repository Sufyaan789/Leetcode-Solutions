class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int ans = 0;

        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == '('){
                balance++;
            }
            else{
                balance--;

                if(balance < 0){
                    balance = 0;
                    ans++;
                }
            }
        }

        ans += balance;
        return ans;
    }
};