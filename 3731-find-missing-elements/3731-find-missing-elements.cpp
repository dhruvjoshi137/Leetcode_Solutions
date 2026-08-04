class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> missing;

        // 1,2,4,5

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1] != nums[i] + 1){
                int current = nums[i]+1;
                while(current < nums[i+1]){
                    missing.push_back(current);
                    current++;
                }
            }
        }
        return missing;
    }
};