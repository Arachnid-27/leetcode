class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static char* mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.empty()) {
            return vector<string>();
        }
        deque<string> str_queue;
        for (int i = 0; mapping[digits[0] - '0'][i]; ++i) {
            str_queue.emplace_back(1, mapping[digits[0] - '0'][i]);
        }
        while (!str_queue.empty()) {
            string& str = str_queue.front();
            if (str.length() == digits.length()) {
                break;
            }
            for (int i = 0; mapping[digits[str.length()] - '0'][i]; ++i) {
                str_queue.push_back(str + mapping[digits[str.length()] - '0'][i]);
            }
            str_queue.pop_front();
        }
        return vector<string>(str_queue.begin(), str_queue.end());
    }
};
