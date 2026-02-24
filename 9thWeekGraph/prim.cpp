#include <bits/stdc++.h>
using namespace std;

typedef double Key;

struct Edge {
    int v;
    int wt;
};
struct Element {
    int id;
    Key key;
};

vector<Element> H;  
vector<int> xmap;    
int nheap;


inline int Left(int i){ return 2 * i; }
inline int Right(int i){ return 2 * i + 1; }
inline int Parent(int i){ return i / 2; }

void SwapHeap(int i, int j){
    swap(H[i], H[j]);
    swap(xmap[H[i].id], xmap[H[j].id]);
}

void UpHeap(int i){
    while(i > 1 && H[Parent(i)].key > H[i].key){
        SwapHeap(i, Parent(i));
        i = Parent(i);
    }
}

void Heapify(int i){
    while(true){
        int l = Left(i);
        int r = Right(i);
        int smallest = i;

        if(l <= nheap && H[l].key < H[smallest].key)
            smallest = l;
        if(r <= nheap && H[r].key < H[smallest].key)
            smallest = r;

        if(smallest == i) break;

        SwapHeap(i, smallest);
        i = smallest;
    }
}

void DecreaseKey(int id, Key new_key){
    int i = xmap[id];
    H[i].key = new_key;
    UpHeap(i);
}

Element DeleteMin(){
    Element minel = H[1];
    SwapHeap(1, nheap);
    nheap--;
    Heapify(1);
    return minel;
}


Key MST_Prim(const vector<vector<Edge>>& G){
    int N = G.size() - 1;
    vector<bool> visited(N + 1, false);
    
    H.assign(N + 1, {0, 0});
    xmap.assign(N + 1, 0);
    nheap = N;

    for(int i = 1; i <= N; i++){
        H[i] = {i, INFINITY};
        xmap[i] = i;
    }
    H[1].key = 0;        
    UpHeap(1);

    
    Key minWeight = 0;

    while(nheap > 0){
        auto e = DeleteMin();
        int u = e.id;
        if (visited[u]) continue;

        visited[u] = true;
        minWeight += e.key;

        for(auto &nx : G[u]){
            int v = nx.v;
            int w = nx.wt;
            if(!visited[v] && w < H[xmap[v]].key){
                DecreaseKey(v, w);
            }
        }
    }
    return minWeight;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<vector<Edge>> G(n + 1);

        for(int i = 1; i <= n; i++){
            int k, m;
            cin >> k >>  m;  

            for(int j = 0; j < m; j++){
                int v, w;
                cin >> v >> w;
                G[i].push_back({v, w});
                G[v].push_back({i, w}); 
            }
        }

        cout << (long long)MST_Prim(G) << endl;
    }
}
