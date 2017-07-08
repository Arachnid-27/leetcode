class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto prev = nums.begin();
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if (*iter != val) {
                *prev = *iter;
                ++prev;
            }
        }
        return prev - nums.begin();
    }
};
