#include <bits/stdc++.h>
using namespace std;

void ucln (int a, int b) {
    int max=0;
    if (a>b) {
        for (int i=1; i<=b; i++) {
            if (a%i==0 && b%i==0) max=i;
        }
    }
    else if (a<b) {
        for (int i=1; i<=a; i++) {
            if (a%i==0 && b%i==0) max=i;
        }
    }
    cout << max << endl;
}

int main () {
    int x,y;
    cin >> x >> y;
    ucln(x,y);
    return 0;
}
