/*

考虑到空间限制和时间限制，可以使用一维动态规划来解决这个问题。这里给出一个C++代码实现：

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

    vector<int> dp(V + 1, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = V; j >= v[i]; --j) {  // 从后往前遍历以确保每个物品只被选择一次
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[V] << endl;

    return 0;
}

/*

这段代码首先读取输入数据，然后定义了一个大小为`V+1`的一维数组`dp`用于存储在不同容量下的最大价值。通过两次循环，外层遍历每件物品，内层从背包的最大容量开始反向遍历至当前考虑的物品体积（这样做是为了避免重复添加同一个物品），更新`dp`数组中的值。最后输出当背包容量为`V`时的最大价值。

注意，由于题目给定的数据范围较大且有空间限制，采用二维DP可能会超出内存限制，因此这里使用了一维DP的方法。此外，这种方法的时间复杂度为O(N*V)，对于给定的规模来说是可接受的。

*/