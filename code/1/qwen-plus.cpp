/*

*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1005;
int dp[MAX_N];

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> v(N), w(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[V] << endl;
    return 0;
}

/*

这个代码实现了0-1背包问题的动态规划解决方案。输入包括物品的数量N、背包的容量V以及每个物品的体积v和价值w。输出是能够放入背包的最大价值。

*/