class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        dfs("", 0, n, v);
        return v;
    }
private:
    void dfs(string s, int m, int n, vector<string>& v) {
        if (s.length() == 2 * n) {
            v.push_back(std::move(s));
            return;
        }
        int k = s.length() - m;
        if (k < m) {
            dfs(s + ')', m, n, v);
        }
        if (m < n) {
            dfs(s + '(', m + 1, n, v);
        }
    }
};
