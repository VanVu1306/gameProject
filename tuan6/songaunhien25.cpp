#include <bits/stdc++.h>
using namespace std;

void in3so (int a[], int size) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            for (int k=0; k<size; k++) {
                if ((a[i]+a[j]+a[k])%25==0) cout << a[i] << " " << a[j] << " " << a[k] << endl;
            }
        }
    }
}

int main () {
    int N;
    cin >> N;
    int a[N];
    for (int i=0; i<N; i++) {
        a[i]= rand()%50;
    }
    in3so(a,N);
    return 0;
}
