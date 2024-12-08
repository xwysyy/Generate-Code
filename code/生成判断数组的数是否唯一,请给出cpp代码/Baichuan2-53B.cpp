#include <iostream>
#include <vector>
#include <set>

bool areUnique(const std::vector<int>& nums) {
    std::set<int> uniqueNumbers(nums.begin(), nums.end());
    return uniqueNumbers.size() == nums.size();
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    if (areUnique(nums)) {
        std::cout << "The array has unique elements." << std::endl;
    } else {
        std::cout << "The array does not have unique elements." << std::endl;
    }

    return 0;
}
