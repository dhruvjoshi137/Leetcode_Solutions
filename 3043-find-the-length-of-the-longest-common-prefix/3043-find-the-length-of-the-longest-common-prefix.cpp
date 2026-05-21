class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> set;
        for(int num : arr1){
            while(num>0){
                set.insert(num);
                num = num/10;
            }// {1} , then 1/10 , which is 0 -> loop ends , then {1,10} , 10/10 = 1 , insert 1 , but 1 is already present so 1/10 = 0 , then {1,10,100} , 100/10 -> already present , 10/10 , already present , 1/10 -> 0 , loop ends , final set is {1,10,100}
        }

        int ans = 0;

        for(int num : arr2){
            while(num>0){
                if(set.count(num)){
                    ans = max(ans , (int)to_string(num).size());
                }
                num = num/10;
            }
        }
        return ans;

    }
};