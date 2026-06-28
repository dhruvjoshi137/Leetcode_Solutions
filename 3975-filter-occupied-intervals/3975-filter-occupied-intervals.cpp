class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin() , occupiedIntervals.end());
        vector<vector<int>> merged;

        merged.push_back(occupiedIntervals[0]);

        for(int i=1;i<occupiedIntervals.size();i++){
            vector<int>& last = merged.back();
            if(last[1]+1 >= occupiedIntervals[i][0]){
                last[1] = max(last[1] , occupiedIntervals[i][1]);
            }else{
                merged.push_back(occupiedIntervals[i]);
            }
        }
        vector<vector<int>> result;
        for(const auto& interval : merged){
            int start = interval[0];
            int end = interval[1];

            if(end < freeStart){
                //there is no possiblity of colliding / intersection
                result.push_back({start , end});
            }else if(start > freeEnd){
                //in this too there is no possibility of intersection
                result.push_back({start,end});
            }else{
                if(start < freeStart){
                    result.push_back({start,freeStart-1});
                }if(end > freeEnd){
                    result.push_back({freeEnd+1 , end});
                }
            }
        }
        return result;

    }
};