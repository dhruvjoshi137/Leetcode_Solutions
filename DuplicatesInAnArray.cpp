class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        int n = nums.size(); // Get the size of the array

        sort(nums.begin(), nums.end()); // Sort the array

        for(int i = 0; i < n - 1; i++) {
            // Check if adjacent elements are equal (indicating a duplicate)
            if(nums[i] == nums[i+1]) { 
                // Avoid inserting duplicates into the result vector
                if(duplicates.empty() || duplicates.back() != nums[i]) {
                    duplicates.push_back(nums[i]);
                }
            }
        }

        return duplicates; // Return the list of duplicates
    }
};
