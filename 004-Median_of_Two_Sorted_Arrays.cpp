class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t n1 = nums1.size(), n2 = nums2.size();
        if (n2 < n1) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        size_t l = 0, r = n1, k = (n1 + n2) / 2;
        while (1) {
            size_t m1 = (l + r) / 2;
            size_t m2 = k - m1;
            if (m1 < n1 && nums1[m1] < nums2[m2 - 1]) {
                l = m1 + 1;
            } else if (m1 > 0 && nums2[m2] < nums1[m1 - 1]) {                
                r = m1;
            } else {
                int a = m1 == n1 ? nums2[m2] : 
                    (m2 == n2 ? nums1[m1] : min(nums1[m1], nums2[m2]));
                if ((n1 + n2) % 2) {
                    return a;
                }
                
                int b = m1 == 0 ? nums2[m2 - 1] : 
                    (m2 == 0 ? nums1[m1 - 1] : max(nums1[m1 - 1], nums2[m2 - 1]));
                return (a + b) / 2.0;
            }
        }
    }
};
