#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin>>N;
    vector<int> energy(N), travel_cost(N);

    for(int i=0; i<N; i++) {
        cin>>energy[i];
    }
    for(int i=0; i<N; i++) {
        cin>>travel_cost[i];
    }

    bool output = false;
    for(int i=0; i<N; i++) {
        int startIdx = i;
        int charge = energy[startIdx];
        for(int j = startIdx+1; ; j = (j+1)%N) {
            charge -= travel_cost[j-1];
            if(charge < 0) break;
            charge += energy[j];

            if(j == startIdx) {
                cout<<i;
                output = true;
                break;
            }
        }
        if(output) break;
    }
    
    if(!output) cout<< -1; 

    return 0;
}
