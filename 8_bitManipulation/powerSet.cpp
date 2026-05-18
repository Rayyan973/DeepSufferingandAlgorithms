#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int> arr) {
    int n = arr.size();
    vector<vector<int>> ans;

    for(int i=0; i <= ((1<<n)-1); i++) {
        vector<int> set;
        for(int j=0; j<n; j++) {
            if(i&(1<<j)) set.push_back(arr[j]);
        }
        ans.push_back(set);
    }

    return ans;
}






int main() {
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> ans = powerSet(arr);

    cout<<"[";
    for(int i=0; i<ans.size(); i++) {
        cout<<"[";
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j];
        }
        cout<<"]";
    }
    cout<<"]"<<endl;





    return 0;
}