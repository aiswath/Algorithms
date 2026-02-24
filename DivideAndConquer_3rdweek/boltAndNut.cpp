#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<int>vec1(n), vec2(n);
        for(int i = 0; i < n; i++) cin >> vec1[i];
        for(int i = 0; i < n; i++) cin >> vec2[i];
        unordered_map<int, int>pos;
        for(int i = 0; i < n; i++) pos[vec2[i]] = i;
        for(int x: vec1){
            cout << pos[x]+1 << " ";
        }
        cout << endl;
    }
}