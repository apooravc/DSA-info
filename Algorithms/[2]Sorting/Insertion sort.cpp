#include <iostream>
using namespace std;

const int maxSize = 100;

void insertionSort(int arr[], int length) {

    for (int j = 1; j < length; j++) {
        int key = arr[j], i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

int main() {

    cout << "Implementing Insertion sort (non-decreasing order)\n\n";

    int length, arr[maxSize];
    cout << "Input array details >>>\n";
    cout << "Enter length, should be <= " << maxSize << ": ";
    cin >> length;
    cout << "Enter sequence: ";
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    insertionSort(arr, length);

    cout << "\nSorted array: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}