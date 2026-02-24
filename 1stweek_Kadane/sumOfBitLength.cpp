# include <iostream>
using namespace std;

unsigned long long int SumOfBitLength(unsigned long long int n)
{
    int m = 64 - __builtin_clzll(n);

    long long total = 0;

    for (int k = 1; k < m; k++){
        total += 1LL * k * (1LL << (k - 1));
    }
    total += 1LL * m * (n - (1LL << (m - 1)) + 1);

    return total;
}
int main()
{   
    int num_test_cases;
    unsigned long long int n;
    cin >> num_test_cases;
    while (num_test_cases--) {
    cin >> n;
    cout << SumOfBitLength(n) << endl;
    }
    return 0;
}