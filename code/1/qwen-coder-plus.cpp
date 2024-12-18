/*

这是一个经典的0-1背包问题。以下是一个使用动态规划解决该问题的C++代码：

*/

#include <iostream>
#include <vector>
using namespace std;

int knapsack(int N, int V, const vector<int>& vi, const vector<int>& wi) {
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int v = 0; v <= V; ++v) {
            if (v >= vi[i - 1]) {
                dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - vi[i - 1]] + wi[i - 1]);
            } else {
                dp[i][v] = dp[i - 1][v];
            }
        }
    }

    return dp[N][V];
}

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> vi(N), wi(N);
    for (int i = 0; i < N; ++i) {
        cin >> vi[i] >> wi[i];
    }

    cout << knapsack(N, V, vi, wi) << endl;

    return 0;
}

/*

这段代码首先读取物品的数量 `N` 和背包的容量 `V`，然后读取每个物品的体积 `vi` 和价值 `wi`。接着使用二维动态规划数组 `dp` 来计算在不同物品数量和不同背包容量下的最大价值。最后输出最大价值。

*/