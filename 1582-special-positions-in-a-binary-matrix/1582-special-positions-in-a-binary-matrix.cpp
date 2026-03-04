class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
    vector<int> r(mat.size()), c(mat[0].size());
    for (int i = 0; i < r.size(); ++i)
        for (int j = 0; j < c.size(); ++j) {
            if (mat[i][j])
                ++r[i], ++c[j];
        }
    int res = 0;
    for (int i = 0; i < r.size(); ++i)
        for (int j = 0; j < c.size(); ++j)
            if (mat[i][j] && r[i] == 1 && c[j] == 1)
                ++res;
    return res;
}
};