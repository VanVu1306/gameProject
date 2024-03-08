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

Point mid_point(const Point& p1,const Point& p2) {
    int mid_x = (p1.x + p2.x) / 2;
    int mid_y = (p1.y + p2.y) / 2;
    Point midPoint(mid_x, mid_y);
    return midPoint;
}

int main () {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Point a (x1, y1), b (x2, y2);
    Point midPoint = mid_point(a,b);
    midPoint.print();
    return 0;
}
