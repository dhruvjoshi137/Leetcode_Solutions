class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxFreq = 0;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            maxFreq = max(maxFreq,freq[nums[i]]);
        }
        int ans=0;

        for(auto &p : freq){
            if(p.second==maxFreq){
                ans+=p.second;
            }
        }
        return ans;
        
    }
};