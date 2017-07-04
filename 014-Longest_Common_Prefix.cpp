class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string result;
        for (size_t i = 0; i < strs[0].length(); ++i) {
            char c = strs[0][i];
            for (size_t j = 1; j < strs.size(); ++j) {
                if (c != strs[j][i]) {
                    return result;
                }
            }
            result += c;
        }
        return result;
    }
};
