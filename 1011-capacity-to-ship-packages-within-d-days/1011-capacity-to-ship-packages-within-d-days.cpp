class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        long long r = 0;
        for (int i = 0; i < n; i++) {
            r += (long long)weights[i];
        }

        int l = *max_element(weights.begin(), weights.end());
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int daysUsed = 1;
            int currentWeight = 0;

            for (int i = 0; i < n; i++) {
                if (currentWeight + weights[i] <= mid) {
                    currentWeight += weights[i];
                } else {
                    daysUsed++;
                    currentWeight = weights[i];
                }
            }

            if (daysUsed <= days) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};