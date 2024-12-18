/*

为了满足空间限制（40KB），我们需要优化动态规划的空间复杂度。通常的0-1背包问题使用二维数组来存储中间结果，但我们可以将其优化为一维数组，从而大大减少空间占用。

下面是实现这一优化的C++代码：

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N), w(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }

    // 一维DP数组，dp[j]表示容量为j时的最大价值
    vector<int> dp(V + 1, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[V] << endl;

    return 0;
}

/*

### 代码解释：
1. **输入部分**：
   - `N` 表示物品的数量。
   - `V` 表示背包的容量。
   - `v` 和 `w` 分别存储每个物品的体积和价值。

2. **一维DP数组**：
   - `dp[j]` 表示在容量为 `j` 的情况下，可以达到的最大价值。

3. **状态转移**：
   - 对于每个物品 `i`，从后向前更新 `dp` 数组，确保每个物品只被处理一次。
   - 更新公式：`dp[j] = max(dp[j], dp[j - v[i]] + w[i])`，表示在当前容量 `j` 下，选择或不选择第 `i` 个物品的最大价值。

4. **输出结果**：
   - 最终 `dp[V]` 即为在容量为 `V` 的背包中可以获得的最大价值。

这种方法将空间复杂度从 `O(N * V)` 降低到 `O(V)`，从而满足了题目中的空间限制。

*/