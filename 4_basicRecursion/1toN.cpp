#include <iostream>
#include <string>
using namespace std;

void printN(int n) {
    cout<<n<<" ";
    if(n == 1) return;
    return printN(n-1);
}


int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"\n";

    printN(5);


    return 0;
}