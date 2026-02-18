class Solution {
public:
    
    void solve(int n, vector<int>& pos, int r, vector<vector<string>>& result) {
        
        // Base case: all rows filled
        if (r == n) {
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                board[i][pos[i]] = 'Q';
            }
            result.push_back(board);
            return;
        }

        // Try placing queen in each column
        for (int col = 0; col < n; col++) {
            
            bool canPlace = true;

            // Check previous rows
            for (int prevRow = 0; prevRow < r; prevRow++) {
                
                // Same column
                if (pos[prevRow] == col) {
                    canPlace = false;
                    break;
                }

                // Diagonal check
                if (abs(prevRow - r) == abs(pos[prevRow] - col)) {
                    canPlace = false;
                    break;
                }
            }

            if (canPlace) {
                pos[r] = col;
                solve(n, pos, r + 1, result);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> pos(n);
        solve(n, pos, 0, result);
        return result;
    }
};