//https://takeuforward.org/strivers-a2z-dsa-course/must-do-pattern-problems-before-starting-dsa

#include <iostream>
using namespace std;

void pattern1(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<5; j++) {
            cout<<"* ";
        }
        cout<<"\n";
    }
}

void pattern2(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout<<"* ";
        }
        cout<<"\n";
    }
}

void pattern3(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

void pattern4(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}

void pattern5(int n) {
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            cout<<"* ";
        }
        cout<<"\n";
    }
}

void pattern6(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

void pattern7(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            cout<<" ";
        }
        for(int j=1; j<=2*i-1; j++) {
            cout<<"*";
        }
        cout<<"\n";
    }
}

void pattern8(int n) {
    for(int i=n; i>=0; i--) {
        for(int j=i; j<=n; j++) {
            cout<<" ";
        }
        for(int j=1; j<=2*i-1; j++) {
            cout<<"*";
        }
        cout<<"\n";
    }
}

void pattern9(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            cout<<" ";
        }
        for(int j=1; j<=2*i-1; j++) {
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=n; i>=0; i--) {
        for(int j=i; j<=n; j++) {
            cout<<" ";
        }
        for(int j=1; j<=2*i-1; j++) {
            cout<<"*";
        }
        cout<<"\n";
    }
}

void pattern10(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=n-1; i>=0; i--) {
        for(int j=1; j<=i; j++) {
            cout<<"*";
        }
        cout<<"\n";
    }
}

void pattern11(int n) {
    int start = 1;
    for(int i=1; i<=n; i++) {
        if(i%2==0) start = 0;
        else start = 1;
        for(int j=1; j<=i; j++) {
            cout<<start<<" ";
            start = 1-start;
        }
        cout<<"\n";
    }
}

void pattern12(int n) {
    int space = 2*(n-1);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout<<j;
        }
        for(int j=1; j<=space; j++) {
            cout<<" ";
        }
        for(int j=i; j>=1; j--) {
            cout<<j;
        }
        space -= 2;
        cout<<"\n";
    }
}

void pattern21(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==0 || j==0 || i==n-1 || j==n-1) cout<<"* ";
            else cout<<"  ";
        }
        cout<<"\n";
    }
}

void pattern22(int n) {
    for(int i=0; i<2*n-1; i++) {
        for(int j=0; j<2*n-1; j++) {
            int top = i, left = j, right = 2*n-2-j, bottom = 2*n-2-i;
            cout<<(n-min(min(top, bottom), min(left, right)));
        }
        cout<<"\n";
    }
}

int main() {
    int n;
    cout<<"Enter rows (n): ";
    cin>>n;

    pattern22(n);
    
    return 0;
}