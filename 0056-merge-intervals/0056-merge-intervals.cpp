class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end()); // sort the array
        vector<vector<int>> merged;
        int n = intervals.size();
        if(n==0) return {};
        merged.push_back(intervals[0]);
        for(int i=1;i<n;i++){
        vector<int>& last = merged.back();
            if(last[1] >= intervals[i][0]){
                last[1] = max(last[1] , intervals[i][1]);
            }else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};