class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = min_element(nums.begin() , nums.end()) - nums.begin();
        int maxi = max_element(nums.begin() , nums.end()) - nums.begin();

        int i = min(mini , maxi);
        int j = max(mini , maxi);

        //3 scenarios
        int front = j + 1;
        int back = n - i;
        int mix = (i+1) + (n-j);

        return min({front , back , mix}); 
    }
};