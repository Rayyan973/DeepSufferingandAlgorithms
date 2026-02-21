#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> arr, int n) {
    for(int i=0; i<n-1; i++) {
        int mini=i;

        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[mini]) mini = j;
        }
        swap(arr[mini], arr[i]);
    }

    cout<<"After selection sort: "<<"\n";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

}


int main() {
    vector<int> arr = {3, 6, 1, 2, 0, 7, 9, 5};
    int n = arr.size();

    //cout<<n<<" "<<sizeof(arr)<<endl;

    cout<<"Before selection sort: "<<"\n";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    selectionSort(arr, n);

    return 0;
}