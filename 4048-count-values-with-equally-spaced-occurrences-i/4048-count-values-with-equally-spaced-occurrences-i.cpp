class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]].push_back(i);
        }

        int occ = 0;

        for(auto& pair : map){
            vector<int>& index = pair.second;
        

        if(index.size() == 3){
            if(index[1] - index[0] == index[2] - index[1]){
                occ++;
            }
        }
        }
        return occ;
    }
};