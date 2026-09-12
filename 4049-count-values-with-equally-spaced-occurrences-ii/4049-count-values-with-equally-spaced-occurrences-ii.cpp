class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]].push_back(i);
        }

        int occ = 0;

        for(auto& pair : map){
            vector<int> index = pair.second;

            if(index.size() >= 3){
                int diff = index[1] - index[0];
                bool equal = true;

                for(int i=2;i<index.size();i++){
                    if(index.at(i) - index.at(i-1) != diff){
                        equal = false;
                        break;
                    }
                }
                if(equal){
                    occ++;
                }
            }
        }
        return occ;
    }
};