#include <bits/stdc++.h>
using namespace std;

void printPattern(int M, int N, int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < M; j++) {
            cout << " ";
        }

        for (int k = 0; k < N; k++) {
            cout << "*";
        }

        M--;
        N += 2;
        cout << endl;
    }
}

int main() {
    int numRows;
    cin >> numRows;
    int M = numRows - 1;
    int N = 1;
    printPattern(M, N, numRows);
    return 0;
}
