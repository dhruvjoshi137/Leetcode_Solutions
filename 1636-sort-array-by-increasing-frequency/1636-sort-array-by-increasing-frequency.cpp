class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x : nums) mp[x]++;

        auto cmp = [](pair<int,int>& a, pair<int,int>& b){
            if(a.first == b.first) 
                return a.second < b.second;
            return a.first > b.first;       
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> minHeap(cmp);

        for(auto it : mp){
            minHeap.push({it.second, it.first});
        }

        vector<int> ans;

        while(!minHeap.empty()){
            auto p = minHeap.top();
            minHeap.pop();

            int freq = p.first;
            int val = p.second;

            while(freq--){
                ans.push_back(val);
            }
        }
        return ans;
    }
};
