class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }
        vector<vector<int>> ans;
        for(auto &p : freq){
            ans.push_back({p.first , p.second});
        }
        return ans;
    }
};