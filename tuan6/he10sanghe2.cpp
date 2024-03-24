#include <bits/stdc++.h>
using namespace std;

void he2 (int n) {
    vector <int> a;
    while (n>0) {
        a.push_back(n%2);
        n=n/2;
    }
    for (int i=a.size()-1; i>=0; i--) {
        cout << a[i];
    }
    cout << endl;
}

int main () {
    int N;
    cin >> N;
    he2(N);
    return 0;
}
