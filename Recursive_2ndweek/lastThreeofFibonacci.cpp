#include <bits/stdc++.h>
using namespace std;

vector<int> memo(1501, -1);

int Fibonacci(int n) {
    n = n % 1500; // Pisano period for mod 1000
    
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    if (memo[n] != -1) return memo[n];
    
    return memo[n] = (Fibonacci(n - 1) + Fibonacci(n - 2)) % 1000;
}

int main() {
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        cout << Fibonacci(n) << "\n";
    }
}
