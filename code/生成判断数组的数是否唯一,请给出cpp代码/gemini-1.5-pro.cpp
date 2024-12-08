#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isUnique(const vector<int>& arr) {
    unordered_set<int> seen;  // 使用 unordered_set 来高效地检查重复

    for (int num : arr) {
        if (seen.count(num)) {  // 如果数字已经存在于 set 中
            return false;       // 返回 false，表示数组不唯一
        }
        seen.insert(num);      // 将数字添加到 set 中
    }

    return true;  // 所有数字都唯一
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 1};
    vector<int> arr3 = {}; // 空数组

    cout << "arr1 is unique: " << (isUnique(arr1) ? "true" : "false") << endl;
    cout << "arr2 is unique: " << (isUnique(arr2) ? "true" : "false") << endl;
    cout << "arr3 is unique: " << (isUnique(arr3) ? "true" : "false") << endl; // 空数组也认为是unique


    return 0;
}
