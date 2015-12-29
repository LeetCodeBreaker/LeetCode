#include <vector>

class Solution {
public:

    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int index1 = 0;
        int index2 = 0;
        while (index2 < n) {
            if (index1 == m) {
                for (int i = index2; i < n; i++) {
                    nums1[m] = nums2[i];
                    m++;
                }
                break;
            }
            
            if (nums1[index1] >= nums2[index2]) {
                m++;
                for (int i = index1; i < m; i++) {
                    int temp = nums1[i];
                    nums1[i] = nums2[index2];
                    nums2[index2] = temp;
                }
                index2++;
            }
            index1++;
        }
        return;
    }
};

int main() {
    Solution solution;
    return 0;
}