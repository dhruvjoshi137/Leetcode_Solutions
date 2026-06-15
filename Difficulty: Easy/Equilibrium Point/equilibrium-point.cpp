class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        
        int n = arr.size();
        int Lsum = 0;
        int totalSum = accumulate(arr.begin() , arr.end() , 0);
        
        for(int i=0;i<n;i++){
            int Rsum = totalSum - Lsum - arr[i];
            if(Rsum == Lsum){
                return i;
            }
            Lsum += arr[i];
        }
        return -1;
    }
};