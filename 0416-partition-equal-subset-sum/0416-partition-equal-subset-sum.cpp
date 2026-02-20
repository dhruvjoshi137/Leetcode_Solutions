class Solution {
    vector<vector<int>> dp;
    int n;
    bool solve(vector<int>& nums , int idx , int target){
        if(idx == n){
            return false;
        }

        if(target == 0) return true;

        if(dp[idx][target]!=-1) return dp[idx][target];

        bool include = 0 , exclude = 0;


        if(target>=nums[idx]){
            //now i can check whether i should include the element or not
            include = solve(nums , idx+1 , target-nums[idx]);
        }
        exclude = solve(nums,idx+1 , target);

        return dp[idx][target] = include || exclude;
    }

public:
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int target = sum/2;

        if(sum%2!=0){
            return false;
        }

        dp=vector<vector<int>>(n+1 , vector<int>(target+1 , -1));
        return solve(nums,0,target);
    }
};