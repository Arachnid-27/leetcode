class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() < 2) {
            return 0;
        }
        int result = 0;
        vector<int> vec(s.length(), 0);
        for (size_t i = 1; i < s.length(); ++i) {
            if (s[i] == ')') {
                size_t j = i - vec[i - 1] - 1;
                if (j >= 0 && s[j] == '(') {
                    vec[i] = vec[i - 1] + 2 + (j > 0 ? vec[j - 1] : 0);
                }
                result = max(result, vec[i]);
            }
        }
        return result;
    }
};
