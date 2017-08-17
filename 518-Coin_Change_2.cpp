class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> vec(amount + 1, 0);
        vec[0] = 1;
        for (int i = 1; i <= coins.size(); ++i) {
            for (int j = coins[i - 1]; j <= amount; ++j) {
                    vec[j] += vec[j - coins[i - 1]];
            }
        }
        return vec[amount];
    }
};
