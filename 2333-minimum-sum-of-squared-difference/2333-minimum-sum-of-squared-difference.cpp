#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        std::vector<long long> counts(100001, 0);
        
        for (size_t i = 0; i < nums1.size(); ++i) {
            int d = std::abs(nums1[i] - nums2[i]);
            counts[d]++;
        }
        
        for (int i = 100000; i > 0; --i) {
            if (counts[i] == 0) continue;
            
            long long current = counts[i];
            
            if (k >= current) {
                counts[i - 1] += current;
                counts[i] = 0;
                k -= current;
            } else {
                counts[i - 1] += k;
                counts[i] -= k;
                k = 0;
                break;
            }
        }
        
        long long total = 0;
        for (int i = 1; i <= 100000; ++i) {
            if (counts[i] > 0) {
                total += counts[i] * ((long long)i * i);
            }
        }
        
        return total;
    }
};
