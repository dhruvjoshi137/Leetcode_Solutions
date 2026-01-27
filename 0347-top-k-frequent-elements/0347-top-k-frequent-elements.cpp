class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minHeap;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto it=mp.begin(); it!=mp.end();it++){
            minHeap.push({it->second , it->first});
            if(minHeap.size()>k){
                minHeap.pop();

            }
        }

        while(minHeap.size()>0){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};