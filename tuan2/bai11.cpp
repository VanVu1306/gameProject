#include <bits/stdc++.h>
using namespace std;
int main () {
    double a, b, c;
    cin >> a >> b >> c;
    for (double i=a; i<=b; i+=c) {
        double p= (i-32)*5/9;
        cout << fixed << setprecision(2) << i << " " << p << " " << p+273.15 << endl;
    }
    return 0;
}
