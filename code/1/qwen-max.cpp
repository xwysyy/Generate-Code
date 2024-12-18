/*

To solve this problem, we can use dynamic programming. The idea is to use a 2D DP table where `dp[i][j]` represents the length of the longest common subarray ending at `nums1[i-1]` and `nums2[j-1]`.

Here's the C++ code to implement this:

*/

#include <vector>
#include <algorithm>
using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            }
        }
    }

    return maxLength;
}

/*

This code initializes a 2D DP table with dimensions `(m+1) x (n+1)` and fills it based on whether the elements of `nums1` and `nums2` match. If they do, it increments the value from the previous diagonal cell (`dp[i-1][j-1]`) by 1. The maximum value in the DP table will be the length of the longest common subarray.

*/