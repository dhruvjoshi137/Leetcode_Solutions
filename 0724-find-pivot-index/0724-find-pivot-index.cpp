class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin() , nums.end() , 0 );
        int Lsum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int Rsum = totalSum - Lsum - nums[i];
            if(Lsum == Rsum){
                return i;
            }
            Lsum += nums[i];
        }
        return -1;
    }
};