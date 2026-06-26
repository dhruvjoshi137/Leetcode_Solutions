class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n;
        vector<int> freq(2*n+1 , 0);

        freq[0 + offset] = 1;
        //base case : a prefix sum of 0 has appeared once

        int curr_sum = 0;
        long long total_count = 0;
        long long smaller_sum_total = 0;


        for(int x : nums){
            if(x == target){
                smaller_sum_total += freq[curr_sum + offset];
                curr_sum++;
            }else{
                curr_sum--;
                smaller_sum_total -= freq[curr_sum + offset];
            }

            total_count += smaller_sum_total;

            freq[curr_sum + offset]++;
        }

        return total_count;
    }
};