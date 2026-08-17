class Solution {
public:
    int minOperations(string s) {
        int n = s.length(), res = 1e8;

        for(int k = 0; k < n; ++k) {
            string t = s.substr(k) + s.substr(0, k);
            int cur = 0;
            
            for(int i = 0; i < n / 2; ++i) {
                int l = t[i] - 'a', r = t[n - i - 1] - 'a';
                int c1 = (l - r + 26) % 26, c2 = (r - l + 26) % 26;
                cur += min(c1, c2);
            }

            res = min(res, k + cur);
        }

        return res;
    }
};