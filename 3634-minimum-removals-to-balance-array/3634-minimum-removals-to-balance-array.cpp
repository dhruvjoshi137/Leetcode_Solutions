class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0,mx=0;
        if(nums.size()==1)
            return 0;
        while(j!=nums.size()-1){
            if((long)nums[i]*k>=nums[j+1]){
                j++;
            }else{
                i++;
            }mx=max(mx,j-i+1);
        }return nums.size()-mx;
    }
};