#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxSize = 100;

int binarySearch(int arr[], int key, int left, int right) {
    if (left <= right) {
        int mid = floor((left + right) / 2);
        if (arr[mid] == key) {
            return mid;
        }
        else if (key < arr[mid]) {
            return binarySearch(arr, key, left, mid - 1);
        }
        else {
            //when arr[mid] < key
            return binarySearch(arr, key, mid + 1, right);
        }
    }

    return -1;
}

int main() {

    cout << "Implementing Binary search\n\n";

    int length, key, arr[maxSize];
    cout << "Input array details >>>\n";
    cout << "Enter length, should be <= " << maxSize << ": ";
    cin >> length;
    cout << "Enter sequence: ";
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    cout << "\nEnter integer to search in array: ";
    cin >> key;
    //sorting entered array in non-decreasing order
    sort(arr, arr + length);

    int x = binarySearch(arr, key, 0, length - 1);
    if (x == -1) {
        cout << "Entered integer could not be found";
    }
    else {
        cout << "Entered integer is present in array";
    }

    return 0;
}