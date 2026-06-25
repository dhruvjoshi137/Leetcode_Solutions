class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            //iterate through every possible starting point of an array
            int cnt = 0;
            for(int j=i;j<n;j++){
                //iterate thorugh every pssible ending point of the array
                if(nums[j] == target){
                //check if the current element matches the target
                    cnt++;
                    //increase the count as the target matches the element
                }
                
                if(cnt > (j-i+1)/2) count++;
                //check if the presence of the target is majority by checking if the count is strictly more than half of the length and increase the count if it is so
            }
        }
        return count;
    }
};