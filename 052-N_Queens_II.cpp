class Solution {
public:
    int totalNQueens(int n) {
        vector<int> cols;
        return dfs(n, cols);
    }
private:
    int dfs(int n, vector<int>& cols) {
        if (cols.size() == n) {
            return 1;
        }
        int s = 0, j = 0, row = cols.size();
        for (int i = 0; i < n; ++i) {
            for (j = 0; j < row; ++j) {
                if (i == cols[j] || (abs(i - cols[j]) == abs(row - j))) {
                    break;
                }
            }
            if (j == row) {
                cols.push_back(i);
                s += dfs(n, cols);
                cols.pop_back();
            }
        }
        return s;
    }
};
