#include <bits/stdc++.h>
using namespace std;

struct Rect {
    int x, y, w, h;
};

struct Ship {
    Rect rect;
    int dx, dy;
};

void move(Ship& ship) {
    ship.rect.x += ship.dx;
    ship.rect.y += ship.dy;
}

void display (const Ship& ship) {
    cout << ship.rect.x << " " << ship.rect.y;
}

signed main () {
    int x1, y1, w1, h1, x2, y2, w2, h2, dx, dy;
    cin >> x1 >> y1 >> w1 >> h1 >> x2 >> y2 >> w2 >> h2 >> dx >> dy;
    Ship ship1;
    Ship ship2;
    ship1.rect={x1,y1,w1,h1};
    ship2.rect={x2,y2,w2,h2};
    ship1.dx=dx;
    ship1.dy=dy;
    ship2.dx=dx;
    ship2.dy=dy;

    int loop=0;
    while (loop < 10) {
        move(ship1); move(ship2);
        display(ship1); display(ship2);
        loop++;
        }

    return 0;
}
