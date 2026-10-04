class Solution {
    double power(double a, int b) {
        // base case
        if (b == 0) {
            return 1;
        }
        if (b == 1) {
            return a;
        }

        // recursive call
        double ans = power(a, b / 2);

        if (b % 2 == 0) {
            // b is even
            return ans * ans;
        } else {
            return a * ans * ans;
        }
    }
public:
    double myPow(double a, long long b) {
        if (b < 0) {
            // For negative exponent, take the reciprocal of the result for positive exponent
            return 1 / power(a, b);
        }
        return power(a, b);
    }
};
