#include <bits/stdc++.h>
using namespace std;

struct Rect {
    int x, y, w, h;
};

struct Ship {
    Rect rect;
    string id;
    int dx, dy;
};

void move(Ship& ship) {
    ship.rect.x += ship.dx;
    ship.rect.y += ship.dy;
}

void display (const Ship& ship) {
    cout << ship.id << " " << ship.rect.x << " " << ship.rect.y;
}

signed main() {
    int x,y,w,h;
    cin >> x >> y >> w >> h;
    string shipID;
    cin >> shipID;
    int dx,dy;
    cin >> dx >> dy;
    Ship ship;
    ship.rect={x,y,w,h};
    ship.id=shipID;
    ship.dx=dx;
    ship.dy=dy;
    move(ship);
    display(ship);

    return 0;
}
