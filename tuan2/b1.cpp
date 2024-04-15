#include <bits/stdc++.h>
using namespace std;
bool ktsnt (int n) {
    if (n<=1) return false;
    for (int i=2; i<=n/2; i++) {
        if (n%i==0) return false;
    }
    return true; }

int main () {
    int n;
    cin >> n;
    if (ktsnt(n)) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}
