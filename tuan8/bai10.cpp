#include <bits/stdc++.h>
using namespace std;

struct ArrayStruct {
    int arr[5];
};

struct OtherStruct {
    int value;
};

struct MainStruct {
    ArrayStruct arrayStruct;
    OtherStruct otherStruct;
};

int main() {
    MainStruct original;
    original.arrayStruct.arr[0] = 10;
    original.arrayStruct.arr[1] = 20;
    original.otherStruct.value = 30;

    MainStruct copy = original;

    cout << "Original arrayStruct address: " << &(original.arrayStruct) << endl;
    cout << "Copy arrayStruct address: " << &(copy.arrayStruct) << endl;

    cout << "Original otherStruct address: " << &(original.otherStruct) << endl;
    cout << "Copy otherStruct address: " << &(copy.otherStruct) << endl;

    cout << "Original array address: " << &(original.arrayStruct.arr) << endl;
    cout << "Copy array address: " << &(copy.arrayStruct.arr) << endl;

    cout << "Original value address: " << &(original.otherStruct.value) << endl;
    cout << "Copy value address: " << &(copy.otherStruct.value) << endl;

    return 0;
}
