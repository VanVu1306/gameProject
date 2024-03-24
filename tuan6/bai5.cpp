#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 5;
    int& ref = a;

    int b = 10;
    ref = b;

    int c = 15;
    ref = c;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    // Câu trả lời:
    // - Biến tham chiếu và biến mà nó chiếu tới đều là một biến trong bộ nhớ.
    //   Biến tham chiếu được coi là một tên khác của biến gốc.
    // - Không thể khai báo một tham chiếu mà chưa chiếu ngay nó tới một biến thường.
    //   Một tham chiếu phải được khởi tạo ngay khi nó được khai báo.
    // - Một tham chiếu chỉ có thể chiếu tới một biến duy nhất và không thể thay đổi ngay đích ban đầu của nó.
    //   Trong ví dụ trên, việc gán ref = b và ref = c đều thay đổi giá trị của a, không phải thay đổi đích ban đầu của ref.

    return 0;
}
