/*

Certainly! You can solve this problem using dynamic programming. Here's a C++ implementation:

*/

#include <vector>
#include <algorithm>

int findLength(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    int maxLength = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = std::max(maxLength, dp[i][j]);
            }
        }
    }

    return maxLength;
}

/*

This function `findLength` takes two integer vectors `nums1` and `nums2` as input and returns the maximum length of a subarray that appears in both arrays. The dynamic programming table `dp` is used to store the lengths of common subarrays ending at different indices of `nums1` and `nums2`. The variable `maxLength` keeps track of the maximum length found.

*/