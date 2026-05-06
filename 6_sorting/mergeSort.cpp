#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;

    int left = low, right = mid+1;

    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid) {
        temp.push_back(arr[left]);
            left++;
    }
    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }

    return;
}

//actual function that does the merging
void mergeSort(vector<int>& arr, int low, int high) {
    if(low >= high) return;

    int mid = low + (high-low)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);

    return;
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

    mergeSort(arr, 0, n-1);

    cout<<"After merge sort: "<<"\n";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    return 0;
}