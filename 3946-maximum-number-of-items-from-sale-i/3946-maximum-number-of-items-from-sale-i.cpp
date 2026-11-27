class Solution {
public:
    int n;
    int mn = INT_MAX;
    vector<int> cnt;

    int go(int i, int rem, vector<vector<int>>& items, vector<vector<int>>& dp) {
        if (i == n) return rem / mn;

        int& ret = dp[i][rem];
        if (~ret) return ret;

        ret = go(i + 1, rem, items, dp);

        if (rem >= items[i][1]) {
            ret = max(ret, go(i + 1, rem - items[i][1], items, dp) + cnt[i]);
        }

        return ret;
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();
        cnt = vector<int>(n);

        for (int i = 0; i < n; i++) {
            mn = min(mn, items[i][1]);
            for (auto& x : items) {
                if (x[0] % items[i][0] == 0) cnt[i]++;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(budget + 1, -1));

        return go(0, budget, items, dp);
    }
};