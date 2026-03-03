class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;

        if (abs(target) > totalSum || (target + totalSum) % 2 != 0)
            return 0;

        int subsetSum = (target + totalSum) / 2;
        return countSubsets(nums, subsetSum);
    }

    int countSubsets(vector<int>& nums, int sum) {
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int j = sum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[sum];
    }
};