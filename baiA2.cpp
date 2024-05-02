#include <bits/stdc++.h>
using namespace std;

int main() {
    int* p = new int;
    int* p2 = p;
    *p = 10;
    delete p;
    *p2 = 100; // lỗi sử dụng con trỏ khi truy cập vùng nhớ đã được giải phóng
    cout << *p2; // lỗi ở trên có thể dẫn đến kết quả in ra không chính xác hoặc lỗi chương trình
    delete p2; // lỗi tiềm ẩn: p2 trỏ tới vùng nhớ đã được giải phóng trước đó,
    return 0;
}

