class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> set(word.begin() , word.end());

        int cnt = 0;

        for(char ch ='a';ch<='z';ch++){
            if(set.count(ch)&&set.count(toupper(ch))){
                cnt++;
            }
            //toupper() is used for converting lowercase to uppercase
        }
        return cnt;
    }
};