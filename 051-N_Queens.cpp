class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> puzzle(n, string(n, '.'));
        vector<int> cols;
        dfs(cols, puzzle, result);
        return result;
    }
private:
    void dfs(vector<int>& cols, vector<string>& puzzle, vector<vector<string>>& result) {
        if (cols.size() == puzzle.size()) {
            result.push_back(puzzle);
            return;
        }
        int j = 0, row = cols.size();
        for (int i = 0; i < puzzle.size(); ++i) {
            for (j = 0; j < row; ++j) {
                if (i == cols[j] || (abs(i - cols[j]) == abs(row - j))) {
                    break;
                }
            }
            if (j == row) {
                cols.push_back(i);
                puzzle[row][i] = 'Q';
                dfs(cols, puzzle, result);
                puzzle[row][i] = '.';
                cols.pop_back();
            }
        }
    }
};
