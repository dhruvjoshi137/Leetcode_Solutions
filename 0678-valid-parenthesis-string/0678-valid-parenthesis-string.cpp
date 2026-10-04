class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for(char c : s){
            low += (c == '(') ? 1 : -1;
            high += (c == ')') ? -1 : 1;

            if(high<0) return false;
            if(low<0) low = 0;
        }
        if(low==0) return true;
        return false;
    }
};