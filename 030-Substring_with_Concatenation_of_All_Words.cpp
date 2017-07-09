class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.length() == 0) {
            return result;
        }
        size_t n = words.size(), m = words[0].length();
        size_t end = s.length() - n * m + 1;
        string str;
        unordered_map<string, pair<int, int>> hash;
        for (string &word : words) {
            hash[word].first += 1;
        }
        for (size_t i = 0; i < end; ++i) {
            size_t j = 0;
            while (j < n) {
                str = s.substr(i + j * m, m);
                auto iter = hash.find(str);
                if (iter != hash.end()) {
                    iter->second.second += 1;
                    if (iter->second.first < iter->second.second) {
                        break;
                    }
                } else {
                    break;
                }
                ++j;
            }
            if (j > 0) {
                if (j == n) {
                    result.push_back(i);
                }
                for (auto &pr : hash) {
                    pr.second.second = 0;
                }
            }
        }
        return result;
    }
};
