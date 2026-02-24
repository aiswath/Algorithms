#include<bits/stdc++.h>
using namespace std;

int longestPath(vector<vector<char>>&board){
    
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int r, c;

        cin >> r >> c;
        vector<vector<char>>board(r, vector<char>(c));
        for(int i=0; i<r; i++){
            for(int j=0; j< c; j++){
                cin >> board[i][j];
            }
        }
        cout << longestPath(board) << endl;
    }
}