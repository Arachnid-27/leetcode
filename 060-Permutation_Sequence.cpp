class Solution {
public:
    string getPermutation(int n, int k) {
        static int factorial[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320 };
        vector<char> nums({'1', '2', '3', '4', '5', '6', '7', '8', '9'});
        k = k - 1;
        string str;
        for (int i = n - 1; i >= 0; --i) {
            int j = k / factorial[i];
            str.push_back(nums[j]);
            nums.erase(nums.begin() + j);
            k %= factorial[i];
        }
        return str;
    }
};
