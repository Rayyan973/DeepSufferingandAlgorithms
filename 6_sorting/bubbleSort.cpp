#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<=i-1; j++) {
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }

    cout<<"After bubble sort: \n";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

}

void bubbleSortOptimal(vector<int> arr) {
    int n = arr.size();
    for(int i=n-1; i>=0; i--) {
        int didSwap = 0;
        for(int j=0; j<=i-1; j++) {
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]); didSwap = 1;
        }
        if(didSwap==0) break;
    }

    cout<<"After bubble sort: \n";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

}


int main() {
    vector<int> arr = {3, 6, 1, 2, 0, 7, 9, 5};
    int n = arr.size();

    //cout<<n<<" "<<sizeof(arr)<<endl;

    cout<<"Before bubble sort: "<<"\n";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    bubbleSortOptimal(arr);

    return 0;
}