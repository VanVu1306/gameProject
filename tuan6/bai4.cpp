#include <bits/stdc++.h>
using namespace std;

void mang(int a[]) {
    a[0] = 10;
}

void strings(string str) {
    str = "string";
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    cout << "a[0] before mang: " << a[0] << endl;
    mang(a);
    cout << "a[0] after mang: " << a[0] << endl;

    string str = "something";
    cout << "str before strings: " << str << endl;
    strings(str);
    cout << "str after strings: " << str << endl;

    // Câu trả lời:
    // - Mảng được truyền theo cơ chế pass-by-reference ngầm định.
    //   Thay đổi mảng trong hàm modifyArray ảnh hưởng trực tiếp đến mảng gốc.
    // - C++ string được truyền theo cơ chế pass-by-value.
    //   Hàm modifyString tạo một bản sao của chuỗi và thay đổi bản sao đó.
    //   Thay đổi không ảnh hưởng đến chuỗi gốc trong hàm main.

    return 0;
}
