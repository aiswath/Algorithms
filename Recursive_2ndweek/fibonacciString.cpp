#include<bits/stdc++.h>
using namespace std;
vector<long long> memo(1001, -1);

long long fib(int n){
    if(n == 1) return 1;
    if(n == 2) return 1;
    if(memo[n] != -1) return memo[n];
    return memo[n] = fib(n-1) + fib(n-2);
}
char findChr(int n, long long k){
    if(n == 1) return 'b';
    if(n == 2) return 'a';
    long long pos = fib(n -1);
    if(k < pos){
        return findChr(n-1,k);
    }
    else{
        return findChr(n-2,k-pos);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long k;
        cin >> n >> k;
        cout << findChr(n,k) << endl;
    }
}