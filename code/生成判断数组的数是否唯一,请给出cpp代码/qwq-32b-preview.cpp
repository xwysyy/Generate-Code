#include <iostream>
#include <vector>
#include <unordered_set>

bool isUnique(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) {
            return false;
        }
        seen.insert(num);
    }
    return true;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {1, 2, 3, 3, 4};
    std::vector<int> nums3 = {5, 5, 5, 5};
    std::vector<int> nums4 = {};

    std::cout << "nums1 unique: " << (isUnique(nums1) ? "Yes" : "No") << std::endl;
    std::cout << "nums2 unique: " << (isUnique(nums2) ? "Yes" : "No") << std::endl;
    std::cout << "nums3 unique: " << (isUnique(nums3) ? "Yes" : "No") << std::endl;
    std::cout << "nums4 unique: " << (isUnique(nums4) ? "Yes" : "No") << std::endl;

    return 0;
}
