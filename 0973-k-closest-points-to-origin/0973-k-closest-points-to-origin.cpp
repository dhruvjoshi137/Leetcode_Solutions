class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int , pair<int,int>>> maxHeap;
        int n = points.size();
        for(int i=0;i<n;i++){
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            maxHeap.push({dist, {points[i][0] , points[i][1]}});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        while(maxHeap.size()>0){
            ans.push_back({maxHeap.top().second.first , maxHeap.top().second.second});
            maxHeap.pop();
        }
        return ans;
    }
};