
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd = 0, even = 1, sum = 0, result = 0;

        for (int num : arr) {
            sum += num; // Current prefix sum
            if (sum % 2 == 0) {
                result = (result + odd) % MOD; // Even - Odd = Odd
                even++; // Even count badhaya
            } else {
                result = (result + even) % MOD; // Odd - Even = Odd
                odd++; // Odd count badhaya
            }
        }
        
        return result;
    }
};