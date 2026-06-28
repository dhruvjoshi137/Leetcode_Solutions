class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin() , nums.end());
        for(int i=n-1;i>=n-k;i--){
            if(mul>0){
                //if mul is not equal to 0 or negative , we can multiply it with our element to get a bigger value
                ans += 1LL * mul*nums[i];
                mul--; //decrement the mul
            }else{
                ans += nums[i];
            }
        }
        return ans;
    }
};