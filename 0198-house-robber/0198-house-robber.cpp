class Solution {
public:

    int rob(vector<int>& nums,int n,int i,vector<int>& dp){

        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        return dp[i] = max(nums[i] + rob(nums,n,i+2,dp),
                           rob(nums,n,i+1,dp));
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,-1);

        return rob(nums,n,0,dp);
    }
};