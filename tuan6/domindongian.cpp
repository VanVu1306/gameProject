#include <bits/stdc++.h>
using namespace std;

void printMinefield(vector<vector<char>>& minefield) {
    int m = minefield.size();
    int n = minefield[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << minefield[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void generateMinefield(vector<vector<char>>& minefield, int m, int n, int k) {
    minefield = vector<vector<char>>(m, vector<char>(n, '.'));

    int placedMines = 0;
    while (placedMines < k) {
        int x = rand() % m;
        int y = rand() % n;
        if (minefield[x][y] == '.') {
            minefield[x][y] = '*';
            placedMines++;
        }
    }
}

int countMines(vector<vector<char>>& minefield, int x, int y, int m, int n) {
    int count = 0;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, m, n) && minefield[nx][ny] == '*') {
            count++;
        }
    }

    return count;
}

void playMineSweeper(int m, int n, int k) {
    vector<vector<char>> minefield;
    generateMinefield(minefield, m, n, k);

    bool gameOver = false;

    while (!gameOver) {
        cout << "Enter coordinates (x, y): ";
        int x, y;
        cin >> x >> y;

        if (!isValid(x, y, m, n)) {
            cout << "Invalid coordinates. Please try again." << endl;
            continue;
        }

        if (minefield[x][y] == '*') {
            cout << "YOU'RE DEAD!" << endl;
            minefield[x][y] = 'X';
            printMinefield(minefield);
            gameOver = true;
        } else {
            int count = countMines(minefield, x, y, m, n);
            minefield[x][y] = count + '0';
            printMinefield(minefield);
        }
    }
}

int main() {
    srand(time(NULL));

    int m, n, k;
    cout << "Enter the dimensions of the minefield (m, n): ";
    cin >> m >> n;
    cout << "Enter the number of mines (k): ";
    cin >> k;

    if (m <= 0 || n <= 0 || k <= 0 || k >= m * n) {
        cout << "Invalid input. Please try again." << endl;
        return 0;
    }

    playMineSweeper(m, n, k);

    return 0;
}
