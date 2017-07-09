class Solution {
public:
    string countAndSay(int n) {
        string seq("1");
        for (int i = 1; i < n; ++i) {
            ostringstream oss;
            int count = 1;
            char c = seq[0];
            for (int j = 1; j < seq.length(); ++j) {
                if (seq[j] != c) {
                    oss << count << c;
                    c = seq[j];
                    count = 1;
                } else {
                    ++count;
                }
            }
            oss << count << c;
            seq = oss.str();
        }
        return seq;
    }
};
