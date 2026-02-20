#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printFreq(int arr[], int n) {
    unordered_map<int, int> map;

    for(int i=0; i<n; i++) {
        map[arr[i]]++;
    }

    for(auto x : map) {
        cout<<x.first<<" -> "<<x.second<<endl;
    }
}

int main() {
    int arr[] = {0, 10, 15, 0, 10, 15, 2, 3, 5, 15, 15, 15, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    printFreq(arr, n);

    return 0;
}