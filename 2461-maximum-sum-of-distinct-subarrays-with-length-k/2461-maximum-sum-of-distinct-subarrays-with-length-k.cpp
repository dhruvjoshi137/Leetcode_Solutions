class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> st;
        long long sum = 0, ans = 0;
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {

            // jab tak duplicate hai, window shrink karo
            while (st.count(nums[j])) {
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }

            // add current element
            st.insert(nums[j]);
            sum += nums[j];

            // jab window size k ho
            if (j - i + 1 == k) {
                ans = max(ans, sum);

                // window slide
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
        }
        return ans;
    }
};
