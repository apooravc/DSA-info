#include <iostream>
#include <cmath>
using namespace std;

const int maxSize = 100;

void merge(int arr[], int p, int q, int r) {

    int n1 = q - p + 1, n2 = r - q;
    int arrLeft[maxSize], arrRight[maxSize];

    //copying sorted sub-arrays
    for (int i = 0; i < n1; i++) {
        arrLeft[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        arrRight[j] = arr[q + 1 + j];
    }

    //merging copies to get a sorted array
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {

        if (arrLeft[i] <= arrRight[j]) {
            arr[k] = arrLeft[i];
            i++;
        }
        else {
            arr[k] = arrRight[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = arrLeft[i];
        k++;
        i++;
    }
    while (j < n2) {
        arr[k] = arrRight[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int p, int r) {

    if (p < r) {
        int q = floor((p + r) / 2);
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main() {

    cout << "Implementing Merge sort (non-decreasing order)\n\n";

    int length, arr[maxSize];
    cout << "Input array details >>>\n";
    cout << "Enter length, should be <= " << maxSize << ": ";
    cin >> length;
    cout << "Enter sequence: ";
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, length - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}