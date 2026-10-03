class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0){
            return false;
        }

        unordered_map<int, int> mp;

        for(int& num : hand){
            mp[num]++;
        }

        sort(hand.begin(), hand.end());

        for(int i = 0; i < n; i++){
            if(mp[hand[i]] > 0){
                for(int j = hand[i]; j < hand[i] + groupSize; j++){
                    if(mp[j] == 0){
                        return false;
                    }

                    mp[j]--;
                }
            }
        }

        return true;
    }
};