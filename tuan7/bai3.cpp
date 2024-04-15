#include <bits/stdc++.h>
using namespace std;

int count_even(int* array, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int count_first = count_even(nums, 5);
    cout << "Dau mang: " << count_first << endl;

    int count_last = count_even(nums + 5, 5);
    cout << "Cuoi mang: " << count_last << endl;

    return 0;
}
