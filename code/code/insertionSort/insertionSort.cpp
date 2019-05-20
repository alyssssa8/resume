#include <string>
#include <iostream>
#include <algorithm>    // std::swap
using namespace std;

void printArray(int arr[], int n);
void insertionSort(int arr[], int n);
int main() {

    int arr[] = { 0,25, 10,2,7,8,9,1,80 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);
    return 0;

}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i]<<" ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
       /* for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];
            }
            else {
                arr[j+1] = temp;
                break;
            }
        }*/
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 &&arr[j] > key ) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

    }
}