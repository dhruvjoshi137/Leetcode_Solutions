class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxi = *max_element(lights.begin() , lights.end());
        int max_P = 0;

        for(long long i : arrivalTime){
            int r = i % period;
            if(r>=maxi){
                max_P = max(max_P , period-r);
            }
        }
        return max_P;
    }
};