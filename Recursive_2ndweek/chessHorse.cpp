#include <iostream>
#include <vector>

using namespace std;

int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(int x, int y, int m, int n, const vector<vector<int>>& sol){
    return ( x >= 0 && x < m && y >= 0 && y < n && sol[x][y] == 0);
}

void printSolution(int m, int n, const vector<vector<int>> & sol){
    for (int x = 0; x < m; x++){
        for (int y = 0; y < n; y++){
            cout << sol[x][y] << (y== n - 1 ? "" : " ");
        }
        cout << "\n";
    }
}
bool solveKnightTour(int m, int n, int x, int y, int moveCount, vector<vector<int>>& sol){
    if (moveCount == m * n){
        return true;
    }

    for (int k = 0; k < 8 ; k++){
        int nextX = x + xMove[k];
        int nextY = y + yMove[k];

        if (isSafe(nextX, nextY, m, n, sol)){
            sol[nextX][nextY] = moveCount + 1;

            if (solveKnightTour(m, n, nextX, nextY, moveCount + 1, sol)){
                return true;
            }
            else{
                sol[nextX][nextY] = 0;
            }
        }
    }
    return false;
}
int main(){
    int t; cin >> t;

    while (t--) {
        int m, n, startX, startY;
        cin >> m >> n >> startX >>startY;

        vector<vector<int>> sol(m, vector<int>(n, 0));

        sol[startX][startY] = 1;

        if (solveKnightTour(m, n, startX, startY, 1, sol)){
            cout << 1 << "\n";
            printSolution(m, n, sol);
        }
        else{
            cout << 0 << "\n";
        }
    

    }
    return 0;
}
