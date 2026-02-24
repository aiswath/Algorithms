#include <bits/stdc++.h>
using namespace std;

const int MAX = 1024;
int board[MAX][MAX];
int tileNo;

void trominoes(int n, int x, int y, int missX, int missY) {
    if (n == 1) return;

    int t = tileNo++;
    int half = n / 2;

    // Which quadrant has the missing tile?
    bool top = (missX < x + half);
    bool left = (missY < y + half);

    // Top-left
    if (top && left)
        trominoes(half, x, y, missX, missY);
    else {
        board[x + half - 1][y + half - 1] = t;   // (1,1)
        trominoes(half, x, y, x + half - 1, y + half - 1); 
    }

    // Top-right
    if (top && !left)
        trominoes(half, x, y + half, missX, missY);
    else {
        board[x + half - 1][y + half] = t;     // (1, 2)
        trominoes(half, x, y + half, x + half - 1, y + half);
    }

    // Bottom-left
    if (!top && left)
        trominoes(half, x + half, y, missX, missY);
    else {
        board[x + half][y + half - 1] = t;    //  (2, 1)
        trominoes(half, x + half, y, x + half, y + half - 1);
    }

    // Bottom-right
    if (!top && !left)
        trominoes(half, x + half, y + half, missX, missY);
    else {
        board[x + half][y + half] = t;       // (2, 2)
        trominoes(half, x + half, y + half, x + half, y + half);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, i, j;
        cin >> n >> i >> j;

        // Reset for each test case
        memset(board, 0, sizeof(board));        
        tileNo = 1;

        // Place trominoes
        trominoes(n, 0, 0, i, j);

        // Print board
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                cout << board[x][y] << " ";
            }
            cout << endl;
        }
        
    }
    return 0;
}
