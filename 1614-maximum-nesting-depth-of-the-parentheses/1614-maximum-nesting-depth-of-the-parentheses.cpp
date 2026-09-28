class Solution {
public:
    int maxDepth(std::string s) {
        int deep = 0;
        int i = 0;
        for (char c : s) {
            if (c == ')') {
                deep--;
            }
            if (c != '(') continue;
            deep++;
            if (deep > i){
             i = deep;
            }
            
                
        }
        return i;
    }
};