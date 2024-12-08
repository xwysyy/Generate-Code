/*

在C++中，要判断一个数组中的元素是否唯一，即每个元素都是独一无二的，没有重复的值，可以通过多种方法实现。下面是一个简单的示例，使用`std::set`来检查数组中是否有重复的元素：

*/

#include <iostream>
#include <vector>
#include <set>

bool isUniqueArray(const std::vector<int>& nums) {
    std::set<int> uniqueNums(nums.begin(), nums.end());
    return uniqueNums.size() == nums.size();
}

int main() {
    std::vector<int> array1 = {1, 2, 3, 4, 5};
    std::vector<int> array2 = {1, 2, 3, 4, 5, 6};

    std::cout << "Array 1 has unique elements: " << (isUniqueArray(array1) ? "Yes" : "No") << std::endl;
    std::cout << "Array 2 has unique elements: " << (isUniqueArray(array2) ? "Yes" : "No") << std::endl;

    return 0;
}

/*

这段代码定义了一个函数`isUniqueArray`，它接受一个整数类型的`std::vector`作为参数，并返回一个布尔值表示数组中的元素是否唯一。函数内部创建了一个`std::set`集合，由于`std::set`不允许重复的元素，所以如果原始数组中没有重复元素，那么`std::set`的大小将与原始数组的大小相同。

在`main`函数中，我们创建了两个数组`array1`和`array2`，然后调用`isUniqueArray`函数来判断它们是否包含唯一的元素，并将结果输出到控制台。

请注意，这种方法的时间复杂度是O(n log n)，因为插入操作需要排序。如果你想要一个线性时间的解决方案，可以使用哈希表（例如`std::unordered_set`）来实现：

*/

#include <iostream>
#include <vector>
#include <unordered_set>

bool isUniqueArray(const std::vector<int>& nums) {
    std::unordered_set<int> seenNums;
    for (int num : nums) {
        if (seenNums.find(num) != seenNums.end()) {
            return false; // Found a duplicate
        }
        seenNums.insert(num);
    }
    return true; // No duplicates found
}

int main() {
    std::vector<int> array1 = {1, 2, 3, 4, 5};
    std::vector<int> array2 = {1, 2, 3, 4, 5, 6};

    std::cout << "Array 1 has unique elements: " << (isUniqueArray(array1) ? "Yes" : "No") << std::endl;
    std::cout << "Array 2 has unique elements: " << (isUniqueArray(array2) ? "Yes" : "No") << std::endl;

    return 0;
}

/*

在这个版本的`isUniqueArray`函数中，我们使用了`std::unordered_set`来存储已经遇到的元素。对于数组中的每个元素，我们检查它是否已经在`std::unordered_set`中；如果是，则返回`false`表示有重复元素。如果遍历完整个数组后都没有发现重复元素，则返回`true`。这种方法的时间复杂度是O(n)，因为它只需要对数组进行一次遍历。

*/