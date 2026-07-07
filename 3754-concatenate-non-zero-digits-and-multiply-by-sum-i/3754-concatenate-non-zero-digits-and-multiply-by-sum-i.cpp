class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;

        string s = to_string(n);
        for (char ch : s) {
            if (ch != '0') {
                int digi = ch - '0';
                sum += digi;
                x = x * 10 + digi;
            }
        }
        return x * sum;
    }
};