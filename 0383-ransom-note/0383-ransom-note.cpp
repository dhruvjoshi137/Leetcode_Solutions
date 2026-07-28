class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length()) return false;

        vector<int> charC(26,0);

        for(char c : magazine){
            charC[c-'a']++;
        }

        for(char c : ransomNote){
            charC[c-'a']--;

            if(charC[c-'a'] < 0){
                return false;
            }
        }
        return true;
    }
};