//https://www.geeksforgeeks.org/quickselect-algorithm/
//Compute time C(n) = COmpute time of half C(n / 2) + some time to decide which half
//average case: O(n)
//worst case: O(n^2
#include <string>
#include <iostream>
#include <algorithm>    // std::swap
using namespace std;

int partition(int arr[], int l, int r);
int kthSmallest(int arr[], int l, int r, int K);
int main() {
    int K = 4;
    int arr[] = { 7,10,4,3,20,15 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int returnValu =  kthSmallest(arr, 0, n - 1, K);
    cout << returnValu << endl;
    return 0;
}


int kthSmallest(int arr[], int l, int r, int K) {

    if (K > 0 && K <= r - l + 1) {
        int index = partition(arr, l, r);
        if (index - l == K - 1) {
            return arr[index];
        }
        if (index - l > K - 1) {
            return  kthSmallest(arr, l, index - 1, K);
        }
        return kthSmallest(arr, index + 1, r, K - index + l - 1);
    }
    return INT_MAX;
    
}

int partition(int arr[], int l, int r) {
    int x = arr[r];
    int i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}