class Solution {
public:
    int uniquePaths(int m, int n) {
        //this question is based on one at a time / either this or that 
        // so this basically means this can be solve using dp
        vector<vector<int>> dp(m , vector<int> (n , 1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};