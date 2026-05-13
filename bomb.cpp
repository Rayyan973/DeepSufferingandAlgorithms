#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2-x1, 2), pow(y2-y1, 2));
}

int main() {
    int N;
    cin>>N;
    vector<vector<int>> dim(N);

    for(int i=0; i<N; i++) {
        cin>>dim[i][0]>>dim[i][1]<<dim[i][2];
    }

    for(int i=0; i<N; i++) {
        for(int j=i; j<N; j++) {
            if()
        }
    }

    return 0;
}
