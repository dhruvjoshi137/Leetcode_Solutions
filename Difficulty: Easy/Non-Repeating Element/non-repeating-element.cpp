class Solution {
public:
    int firstNonRepeating(vector<int>& arr) {

        unordered_map<int,int> freq;

        for(int x : arr){
            freq[x]++;
        }

        for(int x : arr){
            if(freq[x] == 1){
                return x;
            }
        }

        return 0;   // or -1 depending on the problem
    }
};