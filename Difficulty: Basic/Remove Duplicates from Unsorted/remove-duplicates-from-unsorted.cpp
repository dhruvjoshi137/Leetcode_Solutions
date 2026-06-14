class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& nums) {
        // code here
        unordered_set<int> seen;
        vector<int> v;
        
        for(int num : nums){
            if(seen.find(num) == seen.end()){
                v.push_back(num);
                seen.insert(num);
            }
        }
        return v;
    }
};