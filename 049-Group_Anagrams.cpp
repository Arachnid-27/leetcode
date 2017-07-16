class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> hash;
        array<int, 26> counter;
        for (auto &str : strs) {
            fill(counter.begin(), counter.end(), 0);
            for (auto c : str) {
                ++counter[c - 'a'];
            }
            string key;
            for (size_t i = 0; i < 26; ++i) {
                key.append(counter[i], 'a' + i);
            }
            hash[key].push_back(str);
        }
        for (auto &pair : hash) {
            result.push_back(move(pair.second));
        }
        return result;
    }
};
