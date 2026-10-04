class Solution {
public:

    int nextNumber(int n){
        int ans = 0;

        while(n > 0){
            int digit = n % 10;
            ans += digit * digit;
            n = n / 10;
        }

        return ans;
    }

    bool isHappy(int n) {
        
        unordered_set<int> visit;

        while(visit.find(n) == visit.end()){
            visit.insert(n);
            n = nextNumber(n);

            if(n == 1){
                return true;
            }
        }

        return false;
    }
};