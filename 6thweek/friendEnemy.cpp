#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rankv;
    DSU(int n) : parent(n), rankv(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rankv[x] < rankv[y]) swap(x, y);
        parent[y] = x;
        if (rankv[x] == rankv[y]) rankv[x]++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        DSU dsu(2 * n);

        while (m--) {
            int q, x, y;
            cin >> q >> x >> y;

            if (q == 1) { // Make_Friend
                if (dsu.find(x) == dsu.find(y + n)) {
                    cout << 0 << '\n';
                } else {
                    dsu.unite(x, y);
                    dsu.unite(x + n, y + n);
                }
            }
            else if (q == 2) { // Make_Enemy
                if (dsu.find(x) == dsu.find(y)) {
                    cout << 0 << '\n';
                } else {
                    dsu.unite(x, y + n);
                    dsu.unite(x + n, y);
                }
            }
            else if (q == 3) { // Query
                if (dsu.find(x) == dsu.find(y)) {
                    cout << 1 << '\n';  // friends
                } else if (dsu.find(x) == dsu.find(y + n)) {
                    cout << 2 << '\n';  // enemies
                } else {
                    cout << 3 << '\n';  // unknown
                }
            }
        }
    }
    return 0;
}
