#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string convert(int n) {
    if(n==0) return "0";
    if(n == 1) return "1";

    return convert(n >> 1) + ((n&1)?"1":"0");
}

void swap(int& a, int& b) {
    a = a^b;
    b = a^b;
    a = a^b;
}

bool ithBitSetLS(int x, int i) {
    return (x & (1<<i)) > 0;
}

bool ithBitSetRS(int x, int i) {
    return ((x>>i) & 1);
}

int setithBit(int x, int i) {
    return (x | (1<<i));
}

int clearithBit(int x, int i) {
    return (x & (~(1<<i)));
}

int toggleithBit(int x, int i) {
    return (x ^ (1<<i));
}

int removeLastSetBit(int x) {
    return x & (x-1);
}

int removeLastSetBitScam(int x) {
    if(x==0) return 0;
    return (x ^ (1<<__builtin_ctz(x)));
}





int main() {







    return 0;
}