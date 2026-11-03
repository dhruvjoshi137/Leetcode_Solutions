class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int maxi = nums.back();
        int sum = 0;

        for(int i=0;i<n;i++){
            sum += abs(maxi - nums[i]);
        }
        return sum;
    }
};