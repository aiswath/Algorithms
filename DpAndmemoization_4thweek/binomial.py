MOD = 1000000007

def binomial(n, k):

    c = [[0]*(k+1) for _ in range(n+1)]

    for i in range(n+1):
        for j in range(min(i, k)+1):
            if j == 0 or j == i:
                c[i][j] = 1
            else:
                c[i][j] = ( c[i-1][j-1] + c[i - 1][j] ) % MOD
            
    return c[n][k]

for _ in range(int(input())):
    n, k = map(int, input().split())
    print(binomial(n, k))