#include <bits/stdc++.h> 
vector < int > nearlySorted(vector < int > array, int n, int k) {
    priority_queue<int , vector<int> , greater<int>> minHeap;

    vector<int> ans;
    for(int i=0;i<n;i++){
        minHeap.push(array[i]);
        if(minHeap.size()>k){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
       
    }
     while(minHeap.size()>0){
            ans.push_back(minHeap.top());
            minHeap.pop();
    }
    return ans;
}
