class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> saved;
        for (auto num : nums) {
            int l = 0, r = saved.size() - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (saved[m] < num) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            if (r == saved.size() - 1) {
                saved.push_back(num);
            } else if (saved[r + 1] > num) {
                saved[r + 1] = num;
            }
        }
        return saved.size();
    }
};
