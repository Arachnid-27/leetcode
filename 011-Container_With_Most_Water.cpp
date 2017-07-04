class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            if (height[l] < height[r]) {
                result = max(result, height[l] * (r - l));
                ++l;
            } else {
                result = max(result, height[r] * (r - l));
                --r;
            }
        }
        return result;
    }
};
