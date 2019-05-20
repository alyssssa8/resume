#include <string>
#include <iostream>
#include <algorithm>    // std::swap
using namespace std;

int partition(int arr[], int l, int r);
void quickSort(int arr[], int l, int r);
void printArray(int arr[], int size);
//void swap(int* a, int* b);
int main() {

    int arr[] = {0,25, 10,2,7,8,9,1,80};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;

}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    cout << endl;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    

}
//****with out & is the same! could use the method in quick select !
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            //swap(&arr[i], &arr[j]);
            swap(arr[i], arr[j]);
        }
    }
    //swap(&arr[i+1], &arr[high]);
    swap(arr[i + 1], arr[high]);
    printArray(arr, 6);
    return i+1;
}

//void swap(int* a, int* b)
//{
//    int t = *a;
//    *a = *b;
//    *b = t;
//}