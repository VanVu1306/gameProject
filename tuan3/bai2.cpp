#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point (int _x, int _y) {
        x=_x;
        y=_y;
    }
};
// Hàm truyền tham trị
void passByValue(Point p) {
    p.x = 10;
    p.y = 20;
}

// Hàm truyền tham biến
void passByReference(Point& p) {
    p.x = 30;
    p.y = 40;
}

int main() {
    int x, y;
    cin >> x >> y;
    Point point(x,y);

    cout << point.x << ", " << point.y << endl;
    passByValue(point);
    cout << point.x << ", " << point.y << endl;

    passByReference(point);
    cout << point.x << ", " << point.y << endl;

    return 0;
}
