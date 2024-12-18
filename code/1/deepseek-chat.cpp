/*

To solve the problem of finding the maximum length of a subarray that appears in both given arrays `nums1` and `nums2`, we can use a dynamic programming approach. The idea is to create a 2D DP table where `dp[i][j]` represents the maximum length of a common subarray ending at `nums1[i-1]` and `nums2[j-1]`.

Here's the step-by-step approach:

1. **Initialize a DP table**: Create a 2D array `dp` of size `(m+1) x (n+1)` where `m` is the length of `nums1` and `n` is the length of `nums2`. The extra row and column are for base cases where one of the arrays is empty.

2. **Fill the DP table**:
   - If `nums1[i-1] == nums2[j-1]`, then `dp[i][j] = dp[i-1][j-1] + 1`. This means that the current elements match, so we add 1 to the length of the common subarray ending at the previous elements.
   - If `nums1[i-1] != nums2[j-1]`, then `dp[i][j] = 0` because the current elements do not match, so the common subarray length resets to 0.

3. **Track the maximum length**: While filling the DP table, keep track of the maximum value encountered.

4. **Return the maximum length**: After filling the DP table, the maximum value will be the length of the longest common subarray.

Here's the C++ implementation of the above approach:

*/

#include <vector>
#include <algorithm>
using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }

    return maxLen;
}

/*

### Explanation:
- **Initialization**: We initialize a 2D vector `dp` with `(m+1) x (n+1)` dimensions, all set to 0.
- **DP Table Filling**: We iterate through each element of `nums1` and `nums2`. If the current elements match, we update `dp[i][j]` based on the previous diagonal value `dp[i-1][j-1]`. We also update `maxLen` if the current `dp[i][j]` is greater than the previously recorded `maxLen`.
- **Result**: After filling the DP table, `maxLen` contains the length of the longest common subarray.

### Complexity:
- **Time Complexity**: O(m * n), where `m` and `n` are the lengths of `nums1` and `nums2` respectively.
- **Space Complexity**: O(m * n) for the DP table.

This approach efficiently finds the maximum length of a common subarray between the two given arrays.

*/