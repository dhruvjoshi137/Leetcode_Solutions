class Solution {
public:
    int climbStairs(int n, std::vector<int>& costs) {
        int dp0 = 0; 
        int dp1 = 0; 
        int dp2 = 0; 
        
        for (int i = 1; i <= n; ++i) {
            int current_cost = INT_MAX;
            int step_cost = costs[i - 1];

            if (i >= 1) {
                current_cost = min(current_cost, dp2 + step_cost + 1);
            }
            if (i >= 2) {
                current_cost = min(current_cost, dp1 + step_cost + 4);
            }
      
            if (i >= 3) {
                current_cost = min(current_cost, dp0 + step_cost + 9);
            }

            dp0 = dp1;
            dp1 = dp2;
            dp2 = current_cost;
        }
        
        return dp2;
    }
};
