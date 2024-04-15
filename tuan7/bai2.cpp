#include <bits/stdc++.h>
using namespace std;

template<typename T, size_t N>
void f(T (&array)[N]) {
    cout << "Kich thuoc mang trong f(): " << sizeof(array) << endl;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};

    cout << "Kich thuoc mang ngoai f(): " << sizeof(A) << endl;

    f(A);

    return 0;
}
