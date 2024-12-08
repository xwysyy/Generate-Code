#include <iostream>
#include <unordered_set>

bool areElementsUnique(int arr[], int size) {
    std::unordered_set<int> seen;
    for (int i = 0; i < size; ++i) {
        if (seen.find(arr[i]) != seen.end()) {
            // ���Ԫ���Ѿ������ڼ����У��򷵻�false
            return false;
        }
        seen.insert(arr[i]);
    }
    return true;
}

int main() {
    // ��������
    int testArray1[] = {1, 2, 3, 4, 5};
    int testArray2[] = {1, 2, 3, 4, 1}; // �����ظ�Ԫ��

    // ���Ժ���
    std::cout << "Test Array 1 - Unique: " << (areElementsUnique(testArray1, 5) ? "Yes" : "No") << std::endl;
    std::cout << "Test Array 2 - Unique: " << (areElementsUnique(testArray2, 5) ? "Yes" : "No") << std::endl;

    return 0;
}
