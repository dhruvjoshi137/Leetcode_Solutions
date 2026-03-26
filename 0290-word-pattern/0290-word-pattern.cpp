class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        int i = 0;
        for (char ch : pattern) {
            if (i >= s.size()) return false; 

            string temp = "";
            while (i < s.size() && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            i++; 
            if (mp.find(ch) != mp.end()) {
                if (mp[ch] != temp) return false;
            } else {
                mp[ch] = temp;
            }

            if (rev.find(temp) != rev.end()) {
                if (rev[temp] != ch) return false;
            } else {
                rev[temp] = ch;
            }
        }

        if (i < s.size()) return false;

        return true;
    }
};