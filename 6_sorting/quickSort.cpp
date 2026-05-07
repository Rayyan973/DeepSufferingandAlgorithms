#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partitionLow(vector<int>& arr, int low, int high) {
    int pivot = arr[low], i = low, j = high;

    while(i < j) {
        while(arr[i] <= pivot && i <= high-1) {
            i++;
        }
        while(arr[j] > pivot && j >= low+1) {
            j--;
        }
        if(i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);

    return j;
}

//high pivot (standard)
int partitionHigh(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);

    return i+1;
}

void quickSortLow(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pIdx = partitionLow(arr, low, high);
        quickSortLow(arr, low, pIdx-1);
        quickSortLow(arr, pIdx+1, high);
    }
}

void quickSortHigh(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pIdx = partitionHigh(arr, low, high);
        quickSortLow(arr, low, pIdx-1);
        quickSortLow(arr, pIdx+1, high);
    }
}



int main() {
    vector<int> arr = {3, 6, 1, 2, 0, 7, 9, 5};

    int n = arr.size();

    //cout<<n<<" "<<sizeof(arr)<<endl;

    cout<<"Before merge sort: "<<"\n";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    quickSortHigh(arr, 0, n-1);

    cout<<"After merge sort: "<<"\n";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";




    return 0;
}