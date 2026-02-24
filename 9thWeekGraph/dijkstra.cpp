#include <bits/stdc++.h>
using namespace std;

typedef double Key;

struct Edge{
    int v;
    Key wt;
};

struct Element{
    int id;
    Key dist;
    int pred;
};


vector<Element> H;
vector<int> xmap;
int nheap;

inline int Parent(int i) { return i / 2; }
inline int Left(int i)   { return i * 2; }
inline int Right(int i)  { return i * 2 + 1; }

void SwapHeap(int i, int j) {
    swap(H[i], H[j]);
    swap(xmap[H[i].id], xmap[H[j].id]);
}

void UpHeap(int i) {
    while (i > 1 && H[Parent(i)].dist > H[i].dist) {
        SwapHeap(i, Parent(i));
        i = Parent(i);
    }
}

void Heapify(int i) {
    while (true) {
        int l = Left(i), r = Right(i), smallest = i;
        if (l <= nheap && H[l].dist < H[smallest].dist) smallest = l;
        if (r <= nheap && H[r].dist < H[smallest].dist) smallest = r;
        if (smallest == i) break;
        SwapHeap(i, smallest);
        i = smallest;
    }
}

Element DeleteMin() {
    Element minel = H[1];
    SwapHeap(1, nheap);
    nheap--;
    Heapify(1);
    return minel;
}

void DecreaseKey(int id, int pred, Key dist) {
    int i = xmap[id];
    H[i].dist = dist;
    H[i].pred = pred;
    UpHeap(i);
}

Key DijkstraSPTSum(const vector<vector<Edge>> &G) {
    int N = G.size() - 1;
    vector<bool> visited(N + 1, false);
    vector<int> pred(N + 1, 0);  

    H.resize(N + 1, {0, INFINITY, 0});  //id, dist, pred
    xmap.resize(N + 1, 0);  
    nheap = N;

    for (int i = 1; i <= N; i++) {
        H[i] = {i, INFINITY, 0};
        xmap[i] = i;
    }

    H[1].dist = 0;

    while (nheap > 0) {
        auto cur = DeleteMin();
        int v = cur.id;
        if (visited[v]) continue;
        
        visited[v] = true;
        pred[v] = cur.pred;  

        for (auto &edge : G[v]) {               
            int u = edge.v;
            if (visited[u]) continue;
            int idx = xmap[u];  // take new distance (neighbors)
            if (idx == 0) continue;
            if (cur.dist + edge.wt < H[idx].dist) { // compare cur and neighbor
                DecreaseKey(u, v, cur.dist + edge.wt);
            }
        }
    }


    Key sum = 0;
    for (int i = 2; i <= N; i++) { 
        int p = pred[i];
        if (p != 0) {
            for (auto &e : G[p]) {
                if (e.v == i) {
                    sum += e.wt;
                    break;
                }
            }
        }
    }
    return sum;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<Edge>> G(n + 1);

        for (int i = 0; i < n; i++) {
            int k, m;
            cin >> k >> m;
            for (int j = 0; j < m; j++) {
                int v;
                Key w;
                cin >> v >> w;
                G[k].push_back({v, w});
            }
        }

        cout << (long long)DijkstraSPTSum(G) << endl;
    }
    return 0;
}
