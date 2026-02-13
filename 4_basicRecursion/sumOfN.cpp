#include <iostream>
#include <string>
using namespace std;

int sumOfN(int n, int sum=0) {
    if(n == 0) return sum;
    sum += n;
    return sumOfN(n-1, sum);
}


int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"\n";

    int ans = sumOfN(n);
    cout<<"Sum is = "<<ans<<endl;


    return 0;
}