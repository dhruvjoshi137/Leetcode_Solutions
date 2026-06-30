class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        
        int i = 0;
        while (i < n) {
            int cnt = 0;
            int j = 0; 
            
            while (j < n) {
                if (nums[j] < nums[i]) {
                    cnt++;
                }
                j++;
            }
            result.push_back(cnt);
            i++;
        }
        
        return result;
    }
};