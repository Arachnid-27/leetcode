class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<pair<char, int>>> table(1);
        vector<bool> star(1, false);
        for (int i = 0, j = 1; i < p.length(); ++i) {
            if (p[i] == '*') {
                star[j - 1] = true;
                table[j - 1].emplace_back(p[i - 1], j - 1);
            } else {
                star.push_back(false);
                table.emplace_back();
                table[j - 1].emplace_back(p[i], j);
                for (int k = j - 1; k > 0 && star[k]; --k) {
                    table[k - 1].emplace_back(p[i], j);
                }
                ++j;
            }
        }
        for (int k = table.size() - 1; k > 0 && star[k]; --k) {
            table[k - 1].emplace_back('$', table.size() - 1);
        }
        return match(table, 0, s, 0);
    }
private:
    bool match(const vector<vector<pair<char, int>>>& table,
               size_t n, const string& s, size_t m) {
        auto &v = table[n];
        if (m == s.length()) {
            if (n != table.size() - 1) {
                for (auto &pr : v) {
                    if (pr.first == '$') {
                        return true;
                    }
                }
                return false;
            }
            return true;
        }
        for (auto &pr : v) {
            if (pr.first == s[m] || pr.first == '.') {
                if (match(table, pr.second, s, m + 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
