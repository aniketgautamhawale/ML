#include <bits/stdc++.h>
using namespace std;


int partition(int arr[], int p, int r){
    int pivot = arr[r];
    int i = p;
    for (int j = p; j < r; j++){
        if (arr[j] <= pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int partition_r(int arr[], int p, int r){
    int i = p+rand()%(r);
    swap(arr[i], arr[r]);
    return partition(arr, p, r);
}

void quickSort(int arr[], int p, int r){
    if (p < r){
        int q = partition_r(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}


int main(){

    int arr[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout <<endl;

    return 0;
}