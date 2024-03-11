#include <bits/stdc++.h>
using namespace std;
int main () {
    int m,n;
    cin >> m >> n;

    vector <vector<int>> matrix (m,vector <int> (n,0));
    int num=1;
    int top =0;
    int bottom = m-1;
    int left = 0;
    int right = n-1;
    while (top <= bottom && left <= right) {
        for (int i = left; i<= right; i++) {
            matrix [top][i] = num;
            num++;
        }
        top++;
        for (int i=top; i<= bottom; i++) {
            matrix[i][right] = num;
            num++;
        }
        right--;
        if (top<=bottom) {
            for (int i=right; i>=left;i--) {
                matrix[bottom][i] = num;
                num++;
            }
            bottom--;
        }
        if (left<=right) {
            for (int i=bottom; i>=top; i--) {
                matrix[i][left] = num;
                num++;
            }
            left++;
        }
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j< n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
