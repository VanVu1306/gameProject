#include <bits/stdc++.h>
using namespace std;

int round1(double number) {
    if (number >= 0) {
        return static_cast<int>(number + 0.5);
    } else {
        return static_cast<int>(number - 0.5);
    }
}

int round2(double number) {
    if (number >= 0) {
        return (ceil(number));
    } else {
        return (floor(number));
    }
}

int main () {
    double x;
    cin >> x;
    cout << round1(x) << " " << round2(x) << endl;
    return 0;
}
