class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int x : nums) {
            int count = 0;
            int sum = 0;

            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    int other = x / d;

                    // divisor d
                    count++;
                    sum += d;

                    // if both divisors are different
                    if (other != d) {
                        count++;
                        sum += other;
                    }
                }

                // Early break: if divisors > 4, skip
                if (count > 4) break;
            }

            if (count == 4) {
                totalSum += sum;
            }
        }

        return totalSum;
    }
};
