#include <bits/stdc++.h>
using namespace std;
bool ktsnt (int n) {
    if (n<=1) return false;
    for (int i=2; i<=n/2; i++) {
        if (n%i==0) return false;
    }
    return true; }

bool ktshh (int n) {
    int sum=0;
    for (int i=1; i<=n/2; i++) {
        if (n%i==0) sum+=i;}
        if (sum!=n) return false;
        return true;
}

bool ktscp (int n) {
    for (int i=1; i<=n/2; i++) {
        if (i*i==n) return true;
    }
    return false;
}

int main () {
    int n;
    cin >> n;
    for (int i=2; i<=n;i++) {
        if (ktsnt(i)) cout << i << " ";
    }
    cout << endl;
    for (int i=2; i<=n;i++) {
        if (ktshh(i)) cout << i << " ";
    }
    cout << endl;
    for (int i=2; i<=n;i++) {
        if (ktscp(i)) cout << i << " ";
    }
    cout << endl;
    return 0;
}
