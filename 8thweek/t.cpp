#include<bits/stdc++.h>
using namespace std;
void preToPost(vector<int>&arr, int l, int r, vector<int>&out){
    if (l > r) return;
    
    int m = l+1;
    int root = arr[l];
    
    while(m <= r && arr[m] < root) m++;
    
    preToPost(arr, l+1, m-1, out);
    preToPost(arr, m, r, out);
    out.push_back(root);
}

void postToPre(vector<int>&arr, int l, int r, vector<int>&out){
    if (l > r) return;
    
    int m = r-1;
    int root = arr[r];
    
    while(m >= l && arr[m] > root) m--;
    
    out.push_back(root);
    postToPre(arr, l, m, out);
    postToPre(arr, m+1, r-1, out);
    
}
int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        
        cin >> n >> k;
        
        vector<int> arr(n);
        vector<int> res;
        res.reserve(n);
        
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        if (k == 1){
            preToPost(arr, 0, n-1, res);
        }
        else if(k == 2){
            postToPre(arr, 0, n-1, res);
        }
        
        for(int x: res){
            cout << x << " ";
        }
        cout << endl;
    }
}