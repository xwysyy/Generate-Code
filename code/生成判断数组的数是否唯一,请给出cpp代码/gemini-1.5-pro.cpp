/*

*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 方法一：使用 unordered_set
bool areElementsUnique_set(const vector<int>& arr) {
    unordered_set<int> seen;
    for (int num : arr) {
        if (seen.count(num)) { // 如果元素已经存在于集合中
            return false; // 不是唯一的
        }
        seen.insert(num); // 将元素添加到集合中
    }
    return true; // 所有元素都是唯一的
}


// 方法二：排序后检查相邻元素
bool areElementsUnique_sort(vector<int> arr) { // 注意这里传入的是拷贝，不会修改原数组
    sort(arr.begin(), arr.end());
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] == arr[i - 1]) {
            return false;
        }
    }
    return true;
}


int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 1};
    vector<int> arr3 = {}; // 空数组

    cout << "arr1 elements unique (set method): " << areElementsUnique_set(arr1) << endl; // Output: true
    cout << "arr2 elements unique (set method): " << areElementsUnique_set(arr2) << endl; // Output: false
    cout << "arr3 elements unique (set method): " << areElementsUnique_set(arr3) << endl; // Output: true

    cout << "arr1 elements unique (sort method): " << areElementsUnique_sort(arr1) << endl; // Output: true
    cout << "arr2 elements unique (sort method): " << areElementsUnique_sort(arr2) << endl; // Output: false
    cout << "arr3 elements unique (sort method): " << areElementsUnique_sort(arr3) << endl; // Output: true


    return 0;
}

/*


**两种方法的比较：**

* **`unordered_set` 方法:**  平均时间复杂度为 O(n)，其中 n 是数组的大小。它利用哈希表快速查找元素是否存在。空间复杂度也是 O(n)，最坏情况下需要存储所有元素。 这是通常推荐的方法，因为它更简洁且通常更快.

* **排序方法:**  时间复杂度主要取决于排序算法，通常是 O(n log n)。空间复杂度取决于排序算法的实现，可以是 O(1)（原地排序）或 O(n)。 如果数组已经排序，那么这种方法会更快，时间复杂度为O(n).


**选择哪种方法:**

* 对于大多数情况，`unordered_set` 方法是首选，因为它通常更快且代码更简洁。
* 如果对数组的顺序有要求并且不想修改原始数组，则应在`areElementsUnique_sort` 函数中传递数组的副本，例如`areElementsUnique_sort(vector<int>(arr));`  这会增加空间复杂度.
* 如果数组已经排序，那么排序方法（只需遍历一次检查相邻元素）会更高效。


这个改进的代码提供了两种方法，并对空数组情况进行了处理，使代码更健壮。  也对两种方法的优缺点进行了更详细的解释，帮助你根据实际情况选择合适的方法。

*/