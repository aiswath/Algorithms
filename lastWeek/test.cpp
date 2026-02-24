#include<bits/stdc++.h>
using namespace std;

const int White = 0;
const int Gray = 1;
const int Black = 2;

vector<vector<int>> Graph;
vector<int> color;
vector<int> torder;
int toi;
bool hasCycle;

void dfs(int u){
    color[u] = Gray;
    for(int v: Graph[u]){
        if (color[v] == White){
            dfs(v);
            if(hasCycle) return;
        }
        else if(color[v] == Gray){
            hasCycle = True;
            return;
        }
    }
    torder[toi--] = u;
    color[u] = Black;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Graph.assign(n+1, {});
        color.assign(n+1, White);
        torder.resize(n);
        
        for(int i=1; i <=n; i++){
            int k,m;
            cin >> k >> m;
            for(int j = 0; j<m; j++){
                int v; 
                cin >> v;
                Graph[k].push_back[v];
                
            }
        }
        for(int i=1; i<=n; i++){
            if(color[i] == White){
                dfs(i);
                if(hasCycle) break;
            }
        }
        sort(torder.begin(), torder.end());
        
        if(hasCycle){
            cout << -1 << endl;
        }
        else{
            for(int x: torder) cout << x << " ";
                cout << endl;
            }
        }
            
        
}   