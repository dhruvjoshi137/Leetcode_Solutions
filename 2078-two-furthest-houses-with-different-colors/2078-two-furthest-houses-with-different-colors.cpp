class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        
        int first = colors[0];
        int last = colors[n - 1];
        
        int maxDist = 0;

        for (int i = 0; i < n; i++) {
            if (colors[i] != last) {
                maxDist = max(maxDist, (n - 1) - i);
            }
            if (colors[i] != first) {
                maxDist = max(maxDist, i);
            }
        }

        return maxDist;
    }
};