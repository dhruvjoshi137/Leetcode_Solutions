class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int n = arr.size();
        int largest = arr[0];
        int smallest = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i] < smallest){
                smallest = arr[i];
            }else if(arr[i] > largest){
                largest = arr[i];
            }
        }
        return {smallest , largest};
    }
};