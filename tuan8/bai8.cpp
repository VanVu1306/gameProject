#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    Point p;
    p.x = 10;
    p.y = 12;
    cout << &p << endl;
    cout << &(p.x) << endl;
    cout << &(p.y) << endl;
    return 0;
}

//Địa chỉ của biến p là địa chỉ bắt đầu của cấu trúc Point.
//Địa chỉ của trường x là địa chỉ ngay sau địa chỉ của biến p.
//Địa chỉ của trường y là địa chỉ ngay sau địa chỉ của trường x.
