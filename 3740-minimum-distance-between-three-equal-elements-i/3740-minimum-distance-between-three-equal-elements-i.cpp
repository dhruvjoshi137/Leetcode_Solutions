class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 1e9;

        for (auto &it : mp) {
            vector<int> &v = it.second;

            if (v.size() >= 3) {
                for (int i = 0; i + 2 < v.size(); i++) {
                    int dist = 2 * (v[i+2] - v[i]); // optimized formula
                    ans = min(ans, dist);
                }
            }
        }

        return (ans == 1e9) ? -1 : ans;
    }
};