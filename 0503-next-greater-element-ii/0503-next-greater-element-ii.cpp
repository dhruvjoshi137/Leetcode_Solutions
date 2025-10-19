class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            nums.push_back(nums[i]);
        }
        vector<int> res(n , -1);

        stack<int> st;

        for(int i = nums.size() - 1; i >= 0 ; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();

            if(!st.empty()) res[i % n] = nums[st.top()];

            st.push(i);
        }

        return res;
    }
};