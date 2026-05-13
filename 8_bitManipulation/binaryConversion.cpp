#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string intToBinary(int n) {
    if(n == 0) return "0";
    string ans = "";

    while(n > 0) {
        if(n%2 == 1) ans += "1";
        else ans += "0";
        n /= 2;
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

string intToBinaryRecursive(int n) {
    if(n==0) return "0";
    if(n == 1) return "1";

    return intToBinaryRecursive(n/2) + ((n%2 == 0)?"0":"1");
}

string intToBinaryRecursiveBitwiseOperators(int n) {
    if(n==0) return "0";
    if(n == 1) return "1";

    return intToBinaryRecursiveBitwiseOperators(n >> 1) + ((n&1)?"1":"0");
}

int convertToDecimal(string x) {
    int len = x.size();
    int ans = 0, power = 1;

    for(int i=len-1; i>=0; i--) {
        if(x[i] == '1') ans += power;
        power *= 2;
    }

    return ans;
}

int convertToDecimalRecursive(string x, int idx = 0, int ans=0) {
    if(idx == x.size()) return ans;

    int currentBit = (x[idx] - '0');
    return convertToDecimalRecursive(x, idx+1, ans*2 + currentBit);
}

int main() {
    int n = 17;

    string ans = intToBinary(n);

    cout<<ans<<endl;

    string ans2 = intToBinaryRecursive(n);

    cout<<ans2<<endl;

    string ans3 = intToBinaryRecursiveBitwiseOperators(n);

    cout<<ans3<<endl;

    int x = convertToDecimal(ans3);
    cout<<x<<endl;

    x = convertToDecimalRecursive(ans3);
    cout<<x<<endl;

    return 0;
}