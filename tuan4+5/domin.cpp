#include <bits/stdc++.h>
using namespace std;
void printMineField (vector<vector<char>>minefield) {
    int m=minefield.size();
    int n=minefield[0].size();

    vector<vector<int>> count(m, vector<int>(n,0));

    for (int i=0; i< m ; i++) {
        for (int j=0; j< n; j++) {
            if(minefield[i][j]== '*') {
                for (int dx=-1; dx<=1; dx++) {
                    for (int dy=-1; dy<=1; dy++) {
                        if (dx==0 && dy==0) continue;
                        int ni=i+dx;
                        int nj=j+dy;
                        if(ni>=0 && ni<m && nj>=0 && nj<n) {
                            count[ni][nj]++;
                        }
                    }
                }
            }
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (minefield[i][j] == '*') cout << "* ";
            else {
                cout << count[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main () {
    int m,n;
    cin >> m >> n;
    vector <vector<char>> minefield(m, vector<char>(n));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> minefield[i][j];
        }
    }

    printMineField(minefield);
    return 0;
}
