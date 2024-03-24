#include <bits/stdc++.h>
using namespace std;

int toHop(int k, int n) {
    int numerator = 1;
    int denominator = 1;
    for (int i = 1; i <= k; i++) {
        numerator *= n - i + 1;
        denominator *= i;
    }
    return numerator/denominator;
}

int kiemTra(int k, int n) {
    if (k >= 0 && k <= n && n >= 1 && n <= 20) return 1;
    else {return 0;}
}

void nhapKN(int k[], int n[], int *soPhanTu) {
    *soPhanTu = 0;
    int i = 0;
    while (true) {
        cin >> k[i] >> n[i];
        if (k[i] == -1 && n[i] == -1) {
            break;
        }
        if (kiemTra(k[i], n[i])) {
            i++;
            (*soPhanTu)++;
        }
    }
}

int main() {
    const int MAX_SIZE = 100;
    int k[MAX_SIZE];
    int n[MAX_SIZE];
    int soPhanTu = 0;

    nhapKN(k, n, &soPhanTu);

    for (int i = 0; i < soPhanTu; i++) {
        cout << toHop(k[i], n[i]) << endl;
    }

    return 0;
}
