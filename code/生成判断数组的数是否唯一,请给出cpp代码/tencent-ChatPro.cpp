#include <iostream>
using namespace std;

bool areNumbersUnique(int arr[], int size) {
    for (int i = ; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (areNumbersUnique(arr, size)) {
        cout << "数组中的所有数字都是唯一的!" << endl;
    } else {
        cout << "数组中存在重复的数字!" << endl;
    }

    return ;
}
