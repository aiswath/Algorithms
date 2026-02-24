#include<bits/stdc++.h>
using namespace std;

vector<int> uf_parent, uf_size;

void MakeSet(int n){
    uf_parent.resize(n+1);
    uf_size.resize(n+1);
    for(int i = 1; i <= n; i++){
        uf_parent[i] = i;
        uf_size[i] = 1;
    }
}

int UF_Find(int x){
    if(uf_parent[x] != x){
        uf_parent[x] = UF_Find(uf_parent[x]);
    }
    return uf_parent[x];
}

void UF_Union(int x, int y){
    x = UF_Find(x);
    y = UF_Find(y);
    
    if(x == y) return;
    
    if(uf_size[x] < uf_size[y]) swap(x, y);
    uf_parent[y] = x;
    uf_size[x] += uf_size[y];
}

struct Edge{
    int u, v, w;
};

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<Edge> edges;
        
        for(int i = 0; i < n; i++){
            
            int k, m;
            cin >> k >> m;
            
            for(int j = 0; j < m; j++){
                
                int v, w;
                
                cin >> v >> w;
                
                if (k < v){
                    edges.push_back({k, v, w});
                }
            }
        }
        sort(edges.begin(), edges.end(), [](auto&a, auto&b){
            return a.w < b.w;
        });
        
        MakeSet(n);
        int mst = 0, use = 0;
        for(auto &e:edges){
            if (UF_Find(e.u) != UF_Find(e.v)){
                UF_Union(e.u, e.v);
                mst += e.w;
                if(++use == n - 1) break;
            }
        }
        
        cout << mst << endl;
        
    }
}