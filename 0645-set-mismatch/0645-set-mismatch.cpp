class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = -1;
        int n = nums.size();
        vector<int> count(n + 1, 0);

        for(int num : nums) {
            count[num]++;
            if(count[num] == 2) {
                duplicate = num;
            }
        }

        int missing = -1;
        for(int i = 1; i <= n; i++) { 
            if(count[i] == 0) {
                missing = i;
                break;
            }
        }
        return {duplicate, missing};
    }
};