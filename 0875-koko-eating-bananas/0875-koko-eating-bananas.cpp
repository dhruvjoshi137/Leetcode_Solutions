class Solution {
public:

    int calculateMax(vector<int>& piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i =0;i<n;i++){
            maxi = max(maxi , piles[i]);
        }
        return maxi;
    }

    long long calculateHours(vector<int>& piles ,long long hour){
        int n = piles.size();
        long long totalHours = 0;
        for(int i=0;i<n;i++){
            totalHours+= ceil((double)piles[i]/(double)hour);
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = calculateMax(piles);
        int ans = high;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long TotalHours = calculateHours(piles,mid);
            if(TotalHours<=h){
                ans = mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};