/*

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> dp(V + 1, 0);

    for (int i = 0; i < N; ++i) {
        int vi, wi;
        cin >> vi >> wi;
        for (int j = V; j >= vi; --j) {
            dp[j] = max(dp[j], dp[j - vi] + wi);
        }
    }

    cout << dp[V] << endl;

    return 0;
}

/*

### 代码说明：
- `dp[j]` 表示容量为 `j` 的背包所能装下的最大价值。
- 外层循环遍历每件物品，内层循环从大到小遍历背包容量，这样可以避免重复使用同一件物品。
- 每次更新 `dp[j]` 时，比较不放入当前物品和放入当前物品后的价值，取较大值。

### 优化：
- 由于每件物品只能使用一次，内层循环从大到小遍历，避免了重复使用同一件物品。
- 空间复杂度优化为 `O(V)`，符合题目要求。

*/