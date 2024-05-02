#include <bits/stdc++.h>
using namespace std;

int main () {
    char* a = new char[10];
    char* c = a + 3;
    for (int i = 0; i < 9; i++) a[i] = 'a';
    a[9] = '\0';
    cerr <<"a: " << "-" << a << "-" << endl;
    cerr <<"c: " << "-" << c << "-" << endl;
    delete c;
    cerr << "a after deleting c:" << "-" << a << "-" << endl; //lệnh cerr này lỗi vì sau khi giải phóng bộ nhớ của c, con trỏ a vẫn đang trỏ vào vùng nhớ đã được giải phóng
    return 0;
}
