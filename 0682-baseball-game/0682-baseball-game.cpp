class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        int sum = 0;
        for(int i=0;i<operations.size();i++){
            if(operations[i] == "C"){
                ans.pop_back();
            }else if(operations[i] == "D"){
                ans.push_back(ans.back() * 2);
            }else if(operations[i] == "+"){
                ans.push_back(ans.back() + ans[ans.size()-2]);
            }else{
                ans.push_back(stoi(operations[i]));
            }
        }
        sum = accumulate(ans.begin(),ans.end() , 0);
        return sum;
    }
};