/*

当然！以下是一个C++代码示例，用于判断数组中的元素是否唯一：

*/

#include <iostream>
#include <unordered_set>
#include <vector>

bool areElementsUnique(const std::vector<int>& arr) {
    std::unordered_set<int> seen;
    for (int num : arr) {
        if (seen.find(num) != seen.end()) {
            return false; // 如果元素已经存在于集合中，则返回false
        }
        seen.insert(num); // 将元素插入集合
    }
    return true; // 所有元素都是唯一的
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    if (areElementsUnique(arr)) {
        std::cout << "All elements are unique." << std::endl;
    } else {
        std::cout << "There are duplicate elements." << std::endl;
    }

    std::vector<int> arr2 = {1, 2, 3, 4, 4};
    if (areElementsUnique(arr2)) {
        std::cout << "All elements are unique." << std::endl;
    } else {
        std::cout << "There are duplicate elements." << std::endl;
    }

    return 0;
}

/*

这个程序定义了一个函数 `areElementsUnique`，它接受一个整数向量作为参数，并使用一个无序集合（`unordered_set`）来跟踪已经看到的元素。如果发现任何重复元素，该函数将返回 `false`；否则，它将返回 `true`。在 `main` 函数中，我们测试了两个示例数组，一个包含唯一元素，另一个包含重复元素。

*/