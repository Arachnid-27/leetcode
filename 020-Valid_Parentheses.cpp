class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2) {
            return false;
        }
        stack<char> left;
        for (char c : s) {
            switch (c) {
                case ')':
                    if (left.empty() || left.top() != '(') {
                        return false;
                    }
                    left.pop();
                    break;
                case '}':
                    if (left.empty() || left.top() != '{') {
                        return false;
                    }
                    left.pop();
                    break;
                case ']':
                    if (left.empty() || left.top() != '[') {
                        return false;
                    }
                    left.pop();
                    break;
                default:
                    left.push(c);
            }
        }
        return left.empty();
    }
};
