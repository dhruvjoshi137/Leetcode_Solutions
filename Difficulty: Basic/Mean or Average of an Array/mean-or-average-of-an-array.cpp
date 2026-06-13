class Solution {
  public:
    int findMean(vector<int>& arr) {
        int sum = 0;
        int n  = arr.size();
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        return sum/n;
        
    }
};