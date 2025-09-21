class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<i+nums.size();j++){
                int ind = j%nums.size();
                if(nums[ind]>nums[i]){
                    nge[i]=nums[ind];
                    break;
                }
            }
        }
            return nge;
    }
};