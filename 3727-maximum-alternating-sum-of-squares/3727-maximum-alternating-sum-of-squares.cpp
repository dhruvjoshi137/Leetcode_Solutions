#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> sq(n);
        
        for (int i = 0; i < n; ++i) {
            sq[i] = static_cast<long long>(nums[i]) * nums[i];
        }
        
        std::sort(sq.begin(), sq.end());
        
        int k = n / 2;
        long long max_score = 0;
        
        for (int i = 0; i < k; ++i) {
            max_score -= sq[i];
        }
        
        for (int i = k; i < n; ++i) {
            max_score += sq[i];
        }
        
        return max_score;
    }
};
