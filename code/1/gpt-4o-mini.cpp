/*

Here is a C++ solution to solve the problem of finding the maximum length of a subarray that appears in both given integer arrays:

*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLength = 0;
    
    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            }
        }
    }
    
    return maxLength;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    
    int result = findLength(nums1, nums2);
    cout << "The maximum length of a subarray that appears in both arrays is: " << result << endl;
    return 0;
}

/*

This code defines a function `findLength` that uses dynamic programming to determine the maximum length of a subarray present in both arrays. It initializes a 2D vector `dp` to store lengths of common subarrays at different indices. The outer loops iterate over both arrays, updating the `dp` table when an equal pair of elements is found. The result is printed out in the `main` function.

*/