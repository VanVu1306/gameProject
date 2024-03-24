#include <bits/stdc++.h>
using namespace std;

bool soNguyenTo (int a) {
    if (a==1) return 0;
    else {
        for (int i=2; i<=sqrt(a); i++) {
            if (a%i==0) return 0;
        }
    }
    return 1;
}

int main () {
    int N;
    cin >> N;
    for (int i=1; i<=N; i++) {
        if (soNguyenTo(i)) cout << i << " ";
    }
    cout << endl;
    return 0;
}
