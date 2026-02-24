#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int cnt;

void dfs(int u) {
    visited[u] = true;
    cnt++;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        adj.assign(n + 1, {});
        visited.assign(n + 1, false);

        for (int i = 1; i <= n; i++) {
            int k, m;
            cin >> k >> m;
            for (int j = 0; j < m; j++) {
                int v;
                cin >> v;
                adj[k].push_back(v);
                adj[v].push_back(k);   
            }
        }

        vector<int> comps;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cnt = 0;
                dfs(i);
                comps.push_back(cnt);
            }
        }

        sort(comps.begin(), comps.end());

        cout << comps.size() << " ";
        for (int c : comps) cout << c << " ";
        cout << endl;
    }

    return 0;
}
