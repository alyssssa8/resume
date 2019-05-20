#include <string>
#include <iostream>
#include <algorithm>    // std::swap
using namespace std;

void printArray(int arr[], int n);
void shellSort(int arr[], int n);
void printArray(int arr[], int n);
int main() {
    int arr[] = { 0,25, 10,2,7,8,9,1,80 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    shellSort(arr, n);
    printArray(arr, n);
    return 0;
}

void  shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap = gap / 2) {

        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i - gap;
            while (j >= gap && arr[j] > temp) {
                arr[j + gap] = arr[j];
                j= j - gap;
            }
            arr[j + gap] = temp;
        }

    }
 
}



void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}