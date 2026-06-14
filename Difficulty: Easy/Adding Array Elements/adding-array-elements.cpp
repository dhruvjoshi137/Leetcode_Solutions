class Solution {
  public:
    int minOperations(int arr[], int n, int k) {
        // code here
        priority_queue<int , vector<int> , greater<int>>pq;
        
        for(int i = 0; i < n; i++){
            pq.push(arr[i]);
        }
        
        int ops = 0;
        
        while(!pq.empty() && pq.top()<k){
            if(pq.size() < 2){
                return -1;
            }
            
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            
            pq.push(first + second);
            ops ++;
            
        }
        return ops;
    }
};