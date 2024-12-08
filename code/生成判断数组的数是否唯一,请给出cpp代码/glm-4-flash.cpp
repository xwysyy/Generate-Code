#include <iostream>
#include <unordered_set>

bool areElementsUnique(int arr[], int size) {
    std::unordered_set<int> seen;
    for (int i = 0; i < size; ++i) {
        if (seen.find(arr[i]) != seen.end()) {
            // 如果元素已经存在于集合中，则返回false
            return false;
        }
        seen.insert(arr[i]);
    }
    return true;
}

int main() {
    // 测试数组
    int testArray1[] = {1, 2, 3, 4, 5};
    int testArray2[] = {1, 2, 3, 4, 1}; // 包含重复元素

    // 测试函数
    std::cout << "Test Array 1 - Unique: " << (areElementsUnique(testArray1, 5) ? "Yes" : "No") << std::endl;
    std::cout << "Test Array 2 - Unique: " << (areElementsUnique(testArray2, 5) ? "Yes" : "No") << std::endl;

    return 0;
}
