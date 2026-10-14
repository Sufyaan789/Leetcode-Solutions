class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin() , piles.end());
        int n = piles.size();

        while(l <= r){
            int mid = l + (r - l)/2;

            long long cnt = 0;

            for(int i = 0; i < n; i++){
                cnt += (piles[i] + mid - 1) / mid;
            }

            if(cnt <= h){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return l;
    }
};