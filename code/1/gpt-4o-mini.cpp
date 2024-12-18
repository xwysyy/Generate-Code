/*

以下是一个 C++ 代码示例，用于解决给定的 0-1 背包问题。该代码使用动态规划方法来找到在不超过给定容量的情况下的最大价值。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> volume(N + 1);
    vector<int> value(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> volume[i] >> value[i];
    }

    vector<int> dp(V + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = V; j >= volume[i]; j--) {
            dp[j] = max(dp[j], dp[j - volume[i]] + value[i]);
        }
    }

    cout << dp[V] << endl;

    return 0;
}

/*

### 代码说明：
1. **输入部分**: 读取物品数量 `N` 和背包容量 `V`，紧接着读取每个物品的体积和价值。
2. **动态规划数组**: `dp[j]` 表示容量为 `j` 时可获得的最大价值。
3. **状态转移**: 遍历每个物品，从背包容量 `V` 开始，向下遍历到 `volume[i]`，更新最大价值。
4. **输出结果**: 最后输出最大价值 `dp[V]`。

### 注意事项：
- 本代码符合空间限制（约 40KB），同时在给定的时间限制内能够运行完毕。

*/