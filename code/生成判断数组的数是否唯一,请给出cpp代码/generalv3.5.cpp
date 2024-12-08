#include <iostream>
#include <unordered_set>
#include <vector>

bool areElementsUnique(const std::vector<int>& arr) {
    std::unordered_set<int> seenElements;
    for (int num : arr) {
        if (seenElements.find(num) != seenElements.end()) {
            return false; // Found a duplicate element
        }
        seenElements.insert(num);
    }
    return true; // All elements are unique
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5}; // Example array

    if (areElementsUnique(arr)) {
        std::cout << "All elements in the array are unique." << std::endl;
    } else {
        std::cout << "There are duplicate elements in the array." << std::endl;
    }

    return 0;
}
