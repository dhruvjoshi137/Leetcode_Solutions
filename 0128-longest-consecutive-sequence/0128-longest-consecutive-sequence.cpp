class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int currentCnt = 1;
        int longest = 1;

        sort(nums.begin() , nums.end());
        if(nums.empty()) return 0;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1] == nums[i]) continue;
            if(nums[i+1] == nums[i] + 1){
            currentCnt++;
            }
            else{
            longest = max(longest , currentCnt);
            currentCnt = 1; //reset
        }
        }
        return max(longest , currentCnt);
    }
};