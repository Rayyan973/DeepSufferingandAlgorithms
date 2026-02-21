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

int main() {
    vector<int> arr = {3, 6, 1, 2, 0, 7, 9, 5};
    int n = arr.size();

    //cout<<n<<" "<<sizeof(arr)<<endl;

    cout<<"Before insertion sort: "<<"\n";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    vector<int> ans = insertionSort(arr);

    cout<<"After insertion sort: "<<"\n";
    for (int i = 0; i < n; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

    return 0;
}