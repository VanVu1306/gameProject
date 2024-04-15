#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

void passByValue(Point p) {
    cout << &p << endl;
    cout << &(p.x) << endl;
    cout << &(p.y) << endl;
}

void passByReference(Point& p) {
    cout << &p << endl;
    cout << &(p.x) << endl;
    cout << &(p.y) << endl;
}

int main() {
    Point p;
    p.x = 10;
    p.y = 12;

    cout << &p << endl;
    cout << &(p.x) << endl;
    cout << &(p.y) << endl;

    cout << "Truyen tham tri:" << endl;
    passByValue(p);

    cout << "Truyen tham chieu:" << endl;
    passByReference(p);

    return 0;
}
