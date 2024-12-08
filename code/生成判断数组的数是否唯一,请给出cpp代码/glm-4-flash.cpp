/*

以下是一个简单的C++函数，用于判断数组中的元素是否都是唯一的。该函数会返回一个布尔值，如果所有元素都是唯一的，则返回`true`；如果有重复的元素，则返回`false`。

*/

#include <iostream>
#include <unordered_set>

bool areElementsUnique(int arr[], int size) {
    std::unordered_set<int> elements;
    for (int i = 0; i < size; ++i) {
        if (elements.find(arr[i]) != elements.end()) {
            // 如果元素已经在set中，说明有重复
            return false;
        }
        elements.insert(arr[i]);
    }
    return true;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    bool result = areElementsUnique(arr, size);
    if (result) {
        std::cout << "All elements are unique." << std::endl;
    } else {
        std::cout << "There are duplicate elements." << std::endl;
    }

    return 0;
}

/*

这段代码首先包含了必要的头文件，并定义了一个名为`areElementsUnique`的函数，该函数接收一个整数数组`arr`和数组的大小`size`作为参数。它使用`unordered_set`来存储已经遍历过的元素，如果在遍历过程中发现一个元素已经在`unordered_set`中，则表示有重复元素，函数返回`false`。如果遍历完成没有发现重复元素，则返回`true`。

在`main`函数中，我们定义了一个整数数组`arr`并调用`areElementsUnique`函数来判断其元素是否唯一，并根据返回的结果打印相应的信息。

*/