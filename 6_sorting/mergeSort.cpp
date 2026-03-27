#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i=0; i<n1; i++) {
        L[i] = arr[left+i];
    }
    for(int j=0; j<n2; j++) {
        R[j] = arr[mid+1+j];
    }

    int i=0, j=0;
    int k = left;

    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while(i<n1) {
        arr[k++] = L[i++];
    }
    while(i<n2) {
        arr[k++] = R[j++];
    }
}

//actual function that does the merging
vector<int> mergeSort(vector<int>& arr, int left, int right) {
    if(left >= right) return arr;

    int mid = left + (right-left)/2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);

    return arr;
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

    vector<int> ans = mergeSort(arr, 0, n-1);

    cout<<"After merge sort: "<<"\n";
    for (int i = 0; i < n; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

    return 0;
}