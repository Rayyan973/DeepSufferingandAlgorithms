#include <iostream>
#include <string>
using namespace std;

unsigned long long fact(int n) {
    if(n <= 1) return 1;
    return n*fact(n-1);
}


int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"\n";

    unsigned long long ans = fact(n);
    cout<<"Factorial is = "<<ans<<endl;


    return 0;
}