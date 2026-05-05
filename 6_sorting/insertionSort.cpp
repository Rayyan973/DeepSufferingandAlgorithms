#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int> nums) {
    int n = nums.size();

    for(int i=1; i<n; i++) {
        int key = nums[i];
        int j=i-1;

        while(j>=0 && nums[j] > key) {
            nums[j+1] = nums[j];
            j--;
        }

        nums[j+1] = key;
    }

    return nums;
}

void recursiveInsertionSort(vector<int>& arr, int n) {
    if(n <= 1) return;

    recursiveInsertionSort(arr, n-1);

    int last = arr[n-1];
    int j = n-2;
    while(j>=0 && arr[j] > last) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

int main() {
    vector<int> arr = {3, 6, 1, 2, 0, 7, 9, 5};
    int n = arr.size();

    //cout<<n<<" "<<sizeof(arr)<<endl;

    cout<<"Before insertion sort: "<<"\n";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    // vector<int> ans = insertionSort(arr);

    recursiveInsertionSort(arr, n);

    cout<<"After insertion sort: "<<"\n";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    return 0;
}