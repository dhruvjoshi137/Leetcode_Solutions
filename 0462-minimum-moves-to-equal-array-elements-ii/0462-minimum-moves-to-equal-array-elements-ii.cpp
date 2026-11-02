class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        int target = nums[n/2]; //second largest // this was a wrong approach , we had to use median
        int sum = 0;

        for(int i=0;i<n;i++){
            sum += abs(nums[i] - target);
        }

        return sum;
    }
};