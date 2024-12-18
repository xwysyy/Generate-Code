/*

这是一个经典的0/1背包问题。我们可以使用动态规划来解决这个问题，并通过滚动数组的方式优化空间复杂度。以下是C++代码实现：

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

    // 使用滚动数组优化空间复杂度
    vector<int> dp(V + 1, 0);

    for (int i = 0; i < N; ++i) {
        // 倒序遍历，确保每个物品只被选择一次
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[V] << endl;

    return 0;
}

/*

这个程序首先读取输入的物品数量 `N` 和背包容量 `V`，然后读取每件物品的体积 `v[i]` 和价值 `w[i]`。接着使用一个一维数组 `dp` 来存储当前状态下背包的最大价值，并通过倒序遍历的方式确保每个物品只被选择一次。最后输出最大价值。这样可以将空间复杂度从 `O(N * V)` 降低到 `O(V)`。

*/