#include <iostream>
using namespace std;

const int maxSize = 100;

int linearSearch(int arr[], int length, int key) {

    for (int i = 0; i < length; i++) {
        if (arr[i] == key) {
            cout << "Found " << key << " at " << i + 1 << "th position";
            return 1;
        }
    }

    return 0;
}

int main() {

    cout << "Implementing Linear search\n\n";

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
    if (!linearSearch(arr, length, key)) {
        cout << "Entered integer could not be found";
    }

    return 0;
}