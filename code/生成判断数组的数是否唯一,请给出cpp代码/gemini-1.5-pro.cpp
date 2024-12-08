#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isUnique(const vector<int>& arr) {
    unordered_set<int> seen;  // ʹ�� unordered_set ����Ч�ؼ���ظ�

    for (int num : arr) {
        if (seen.count(num)) {  // ��������Ѿ������� set ��
            return false;       // ���� false����ʾ���鲻Ψһ
        }
        seen.insert(num);      // ��������ӵ� set ��
    }

    return true;  // �������ֶ�Ψһ
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 1};
    vector<int> arr3 = {}; // ������

    cout << "arr1 is unique: " << (isUnique(arr1) ? "true" : "false") << endl;
    cout << "arr2 is unique: " << (isUnique(arr2) ? "true" : "false") << endl;
    cout << "arr3 is unique: " << (isUnique(arr3) ? "true" : "false") << endl; // ������Ҳ��Ϊ��unique


    return 0;
}
