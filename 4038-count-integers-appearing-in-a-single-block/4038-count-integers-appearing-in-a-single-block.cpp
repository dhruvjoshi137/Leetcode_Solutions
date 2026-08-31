class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_map<int,int> blockCount;

        blockCount[nums[0]] =1;

        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[i-1]){
                blockCount[nums[i]]++;
            }
        }

        int okay = 0;
        for(auto& pair : blockCount){
            if(pair.second == 1){
                okay++;
            }
        }
        return okay;
    }
};