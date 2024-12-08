/*

*/

#include <iostream>
#include <vector>
#include <unordered_set>

bool hasUniqueNumbers(const std::vector<int>& arr) {
    std::unordered_set<int> uniqueNumbers;

    for (const int& num : arr) {
        if (uniqueNumbers.count(num)) {
            return false; // 如果number已经存在于集合中，说明不唯一
        }
        uniqueNumbers.insert(num);
    }

    return true; // 所有数字都是唯一的
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    if (hasUniqueNumbers(arr)) {
        std::cout << "数组中的数字都是唯一的" << std::endl;
    } else {
        std::cout << "数组中存在重复的数字" << std::endl;
    }

    return ;
}

/*

这段C++代码定义了一个函数`hasUniqueNumbers`，它接受一个整数类型的`std::vector`作为参数，并返回一个布尔值来表示这个数组里的数字是否唯一。使用了C++的`std::unordered_set`来帮助检查重复的数字，因为它提供了O(1)的平均查找时间。

*/