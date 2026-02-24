#include <bits/stdc++.h>
using namespace std;

void preToPost(const vector<int>& arr, int l, int r, vector<int>& out) {
    if (l > r) return;

    int root = arr[l];
    int m = l + 1;


    while (m <= r && arr[m] < root) m++;

    preToPost(arr, l + 1, m - 1, out);
    preToPost(arr, m, r, out);
    out.push_back(root);
}


void postToPre(const vector<int>& arr, int l, int r, vector<int>& out) {
    if (l > r) return;

    int root = arr[r];
    int m = r - 1;


    while (m >= l && arr[m] > root) m--;

    out.push_back(root);
    postToPre(arr, l, m, out);
    postToPre(arr, m + 1, r - 1, out);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> result;
        result.reserve(n);

        if (k == 1) {
        
            preToPost(arr, 0, n - 1, result);
        } else {
    
            postToPre(arr, 0, n - 1, result);
        }

        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        
        }
        cout << endl;
    }

    return 0;
}
