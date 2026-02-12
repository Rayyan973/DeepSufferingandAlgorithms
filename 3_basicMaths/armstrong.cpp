#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool armstrong(int n) {
    int sum = 0;
    int a = n;
    while(a>0) {
        int digit = a%10;
        sum += (digit*digit*digit);
        a /= 10;
    }
    if(sum == n) return true;
    return false;
}

int main() {
    int n;
    cout<<"Enter number: ";
    cin>>n;

    if(armstrong(n)) cout<<"yes its armstrong\n";
    else cout<<"no it aint armstrong\n";

    return 0;
}