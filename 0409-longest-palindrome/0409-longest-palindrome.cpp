class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> set;
        int cnt = 0;

        for(char str : s){
            if(set.find(str) == set.end()){
                set.insert(str);
            }else{
                cnt += 2; // i have found a pair that can be included in my palindrome
                set.erase(str);
            }
        }
        if(!set.empty()){
            cnt++;
        }
        return cnt;
    }
};