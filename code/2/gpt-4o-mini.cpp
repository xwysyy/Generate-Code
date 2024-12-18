/*

这是一个典型的 0-1 背包问题。我们可以使用动态规划来解决这个问题，同时通过优化空间复杂度来满足条件。以下是优化后的 C++ 代码：

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N + 1);
    vector<int> w(N + 1);
    
    for (int i = 1; i <= N; ++i) {
        cin >> v[i] >> w[i];
    }

    vector<int> dp(V + 1, 0); // dp[i]表示容量为i时的最大价值

    for (int i = 1; i <= N; ++i) {
        for (int j = V; j >= v[i]; --j) { // 从后往前更新，避免重复计算
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[V] << endl; // 输出最大价值
    return 0;
}

/*

### 代码说明：
1. **输入处理**：首先读取物品的数量 `N` 和背包的容量 `V`，然后读取每个物品的体积和价值。
2. **动态规划数组**：使用一维数组 `dp` 来存储不同容量下的最大价值，初始化为0。
3. **状态转移**：遍历每个物品，并从背包的最大容量向下更新，以确保每个物品只能使用一次。
4. **输出结果**：最后输出容量为 `V` 的最大价值。

### 优化空间：
通过采用一维数组而不是二维数组，空间复杂度从 O(N*V) 优化到 O(V)，在时间复杂度上仍然是 O(N*V)，满足题目中对空间的限制要求。

*/