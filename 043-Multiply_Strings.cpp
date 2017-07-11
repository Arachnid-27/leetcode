class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string s(num1.length() + num2.length(), '0');
        int n1, n2, m, c = 0;
        for (size_t i = 0; i < num1.length(); ++i) {
            n1 = num1[num1.length() - 1 - i] - '0';
            for (size_t j = 0; j < num2.length(); ++j) {
                n2 = num2[num2.length() - 1 - j] - '0';
                m = (s[i + j] - '0') + n1 * n2 + c;
                c = m / 10;
                s[i + j] = m % 10 + '0';
            }
            if (c) {
                s[i + num2.length()] = c + '0';
                c = 0;
            }
        }
        if (s[s.length() - 1] == '0') {
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
