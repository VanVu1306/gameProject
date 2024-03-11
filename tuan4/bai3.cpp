#include <bits/stdc++.h>
using namespace std;

int main () {
    char daytab1[2][12] = {
  {31,28,31,30,31,30,31,31,30,31,30,31},
  {31,29,31,30,31,30,31,31,30,31,30,31}
  };

  char daytab2[2][12] = {
  31,28,31,30,31,30,31,31,30,31,30,31,
  31,29,31,30,31,30,31,31,30,31,30,31
  };
  //mang1
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 12; j++) {
            cout << static_cast<int>(daytab1[i][j]) << " ";
        }
        cout << endl;
    }

    //mang2
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 12; j++) {
            cout << static_cast<int>(daytab2[i][j]) << " ";
        }
        cout << endl;
    }

    // Thử chỉ khởi tạo một phần của mảng
    char daytab3[2][12] = {
        31, 28, 31, 30, 31, 30, 31,
        31, 29, 31, 30, 31, 30, 31
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 12; j++) {
            cout << static_cast<int>(daytab3[i][j]) << " ";
        }
        cout << endl;
    }

    // Thử bỏ giá trị kích thước trong khai báo mảng
    char daytab4[][12] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 12; j++) {
            cout << static_cast<int>(daytab4[i][j]) << " ";
        }
        cout << endl;
    }

    return 0;
}
