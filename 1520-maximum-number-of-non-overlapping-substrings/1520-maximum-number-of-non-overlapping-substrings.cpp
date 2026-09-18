class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, pair<int,int>> indices;

        for(int i = 0; i < n; i++) {
            if(indices.count(s[i])) {
                indices[s[i]].second = i;
            } else {
                indices[s[i]] = {i, i};
            }
        }

        vector<vector<int>> intervals;

        for(auto it : indices) {
            auto [l, r] = it.second;

            bool valid = true;
            for(int i = l; i <= r; i++) {
                if(indices[s[i]].first < l) {
                    valid = false;
                    break;
                }
                r = max(r, indices[s[i]].second);
            }
            if(valid) intervals.push_back({l, r});
        }

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        vector<string> ans;
        int prevEnd = -1;

        for(auto it : intervals) {
            if(it[0] > prevEnd) {
                ans.push_back(s.substr(it[0], it[1] - it[0] + 1));
                prevEnd = it[1];
            }
        }

        return ans;
    }
};