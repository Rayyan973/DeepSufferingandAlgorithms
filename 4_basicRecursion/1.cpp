#include <iostream>
#include <string>
using namespace std;

void printN(string s, int n, int count=0) {
    if(count == n) return;
    cout<<(count+1)<<" "<<s<<"\n";
    return printN(s, n, ++count);
}


int main() {
    string s;
    cout<<"Enter string: \n";
    getline(cin, s);
    cout<<"\n\n";

    printN(s, 5);


    return 0;
}