class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m - 1;

        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;
            if (matrix[mid][0] < target)
                top = mid + 1;
            else if (matrix[mid][0] > target)
                bottom = mid - 1;
            else
                return true;
        }

        int left = 0;
        int right = n - 1;

        while (bottom >= 0 && left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[bottom][mid] < target)
                left = mid + 1;
            else if (matrix[bottom][mid] > target)
                right = mid - 1;
            else
                return true;
        }

        return false;
    }
};