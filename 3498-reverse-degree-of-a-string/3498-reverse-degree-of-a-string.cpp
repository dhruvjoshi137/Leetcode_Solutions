class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            int pos = i+1;
            int revPos = 26 - (s[i] - 'a');
            ans += pos * revPos;
        }
        return ans;
    }
};