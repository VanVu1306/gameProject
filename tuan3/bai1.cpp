#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
    Point (int _x, int _y) {
        x=_x;
        y=_y;
    }
    void print () {
        cout << x << " " << y;
    }
};

int main () {
    int x, y;
    cin >> x >>y;
    Point point(x,y);
    point.print();
    return 0;
}

