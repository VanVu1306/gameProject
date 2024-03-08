#include <bits/stdc++.h>
using namespace std;

struct Point {
    int a,b;
    Point (int _a, int _b) {
        a=_a;
        b=_b;
    }
};

struct Rect {
    int x, y, w, h;
    Rect (int _x, int _y, int _w, int _h) {
        x=_x;
        y=_y;
        w=_w;
        h=_h;
    }

    bool contains (const Point&p) const {
        return p.a >= x && p.a <= x + w && p.b >= y && p.b <= y + h;
    }
};

int main () {
    int x, y, w, h, a, b;
    cin >> x >> y >> w >> h >> a >> b;
    Rect rect (x,y,w,h);
    Point p (a,b);
    cout << rect.contains(p) << endl;
    return 0;
}
