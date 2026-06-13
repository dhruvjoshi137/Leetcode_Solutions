class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        vector<pair<int,int>> v;
        for(auto it : mp){
            v.push_back(it);
        }
        sort(v.begin() , v.end() , [&](pair<int,int> a , pair<int,int> b){
            if(a.second == b.second){
                return a.first< b.first;
            }else{
                return a.second>b.second;
            }
        });
        
        vector<int> ans;
        for(auto it : v){
            while(it.second--){
                ans.push_back(it.first);
            }
        }
        return ans;
        
        
    }
};