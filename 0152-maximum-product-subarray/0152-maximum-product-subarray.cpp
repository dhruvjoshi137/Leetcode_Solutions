class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int currMin = nums[0];
        int maxSoFar = nums[0];

        for(int i=1;i<n;i++){
            if(nums[i]<0){
                //if nums[i] is negative , then my currMax will become the currMin 
                swap(currMax , currMin);
            }

            currMax = max(nums[i] , currMax*nums[i]);
            currMin = min(nums[i] , currMin*nums[i]);
            maxSoFar = max(maxSoFar , currMax);
        }
        return maxSoFar;
    }
};