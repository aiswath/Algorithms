#include <bits/stdc++.h>
using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector<vector<int>> G;
vector<int> color;
vector<int> torder;
int toi;

bool hasCycle;  

void DFS(int u)
{
    color[u] = GRAY;        // visiting started

    for (int v : G[u]) {
        if (color[v] == WHITE) {
            DFS(v);
            if (hasCycle) return;
        }
        else if (color[v] == GRAY) {
    
            hasCycle = true;
            return;
        }
    }

    torder[toi--] = u;      // store post-order
    color[u] = BLACK;       // visiting done
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        G.assign(n + 1, {});
        color.assign(n + 1, WHITE);
        torder.resize(n);
        toi = n - 1;
        hasCycle = false;

        for (int i = 1; i <= n; i++) {
            int k, m;
            cin >> k >> m;
            for (int j = 0; j < m; j++) {
                int v;
                cin >> v;
                G[k].push_back(v);
            }
        }

        for (int u = 1; u <= n; u++) {
            if (color[u] == WHITE) {
                DFS(u);
                if (hasCycle) break;
            }
        }

        sort(torder.begin(), torder.end());

        if (hasCycle) {
            cout << -1 << endl;
        } else {
            for (int x: torder) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
