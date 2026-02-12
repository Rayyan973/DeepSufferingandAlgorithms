#include <iostream>
using namespace std;
#include <bits/stdc++.h>;

int countDigits(int n) {
    int count = 0;
    while(n>0) {
        count++;
        n /= 10;
    }
    return count;
}

//basically finding the ceiling of  logbase10(n) gives you the required answer.
//(or else cast log10(n)+1 to int, same thing)
int countDigitsOptimal(int n) {
    int count = 0;
    count = int(log10(n)+1);
    return count;
}

int main() {
    int n;
    cout<<"Enter number boss: ";
    cin>>n;

    int count = countDigits(n);
    cout<<"number of digits in the given number is: "<<count<<"\n";

    count = countDigitsOptimal(n);
    cout<<"number of digits in the given number (solved optimally) is: "<<count<<"\n";

    return 0;
}