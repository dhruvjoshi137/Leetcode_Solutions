class Solution {
public:
    bool isPalindromic(string s) {
        string ss = "";
        for(char c : s){
            ss += bitset<8>(c).to_string();
        }
        string reversed = ss;
        reverse(reversed.begin() , reversed.end());

        return ss==reversed;
    }
};