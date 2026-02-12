#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int GCD(int a, int b) {
    int gcd = 1;
    int minimum = min(a, b);

    for(int i=1; i<=minimum; i++) {
        if(a%i == 0 && b%i == 0) gcd = i;
    }

    return gcd;
}
//a slightly more optimal way would be to run the loop from min(a, b) down to zero
//and break whenever the first common factor is found.

//euclidean algorithm based optimisation
//this algo states that the gcd remains same for (a, b-a)
//considering a is the smaller number obv.
int GCDOptimal(int a, int b) {
    if(a==0) return b;
    if(b==0) return a;
    if(a==b) return a;

    if(a>b) return GCDOptimal(a-b, b);
    else return GCDOptimal(a, b-a);
}

//an even more optimal way is to do (a, a%b)
int GCDswag(int a, int b) {
    if (b == 0) return a;
    return GCDOptimal(b, a % b);
}

int main() {
    int a, b;
    cout<<"Enter numberrrssss: ";
    cin>>a>>b;
    int gcd = GCDswag(a, b);
    cout<<"GCD of "<<a<<" and "<<b<<" is: "<<gcd<<"\n";

    return 0;
}