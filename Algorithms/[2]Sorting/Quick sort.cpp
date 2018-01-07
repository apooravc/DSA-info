#include <iostream>
using namespace std;

const int maxSize = 100;

int partition(int arr[], int p, int r) {

    //x is the pivot
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[r];
    arr[r] = arr[i + 1];
    arr[i + 1] = temp;

    return i + 1;
}

void quickSort(int arr[], int p, int r) {

    if (p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main() {

    cout << "Implementing Quick sort\n\n";

    int length, arr[maxSize];
    cout << "Input array details >>>\n";
    cout << "Enter length, should be <= " << maxSize << ": ";
    cin >> length;
    cout << "Enter sequence: ";
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, length - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}