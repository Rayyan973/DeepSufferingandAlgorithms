#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin>>N;
    vector<pair<int, int>> dim(N);

    for(int i=0; i<N; i++) {
        cin>>dim[i].first>>dim[i].second;
    }


    sort(dim.begin(), dim.end(), greater<pair<int, int>>());

    stack<pair<int, int>> st;
    st.push(dim[0]);

    int counter = 1;

    for(int i=1; i<N; i++) {
        pair<int, int> top = st.top();
        if((dim[i].first < top.first) && (dim[i].second < top.second)) {
            st.push(dim[i]);
            counter++;
        }
    }

    cout<<counter;

    return 0;
}
