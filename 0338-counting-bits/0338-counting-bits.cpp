class Solution {
private:
    int fbit(int n) {
        int count = 0;

        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }

public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        for (int i = 1; i <= n; i++) {
            ans[i] = fbit(i);
        }

        return ans;
    }
};