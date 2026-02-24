def chainedMatrix(d):
    n = len(d) - 1
    dp = [[0] * (n+1) for _ in range(n + 1)]
    split = [[0] * (n + 1) for _ in range(n+1)]

    for chainLen in range(2, n + 1):
        for i in range(1, n - chainLen + 2):
            j = i + chainLen - 1
            dp[i][j] = float("inf")
            for k in range(i, j):
                cost = dp[i][k] + dp[k+1][j] + d[i-1]*d[k]*d[j]
                if cost < dp[i][j]:
                    dp[i][j] = cost
                    split[i][j] = k     
    
    def bestOrder(i, j):
        if i == j:  
            return f"M{i}"
        k = split[i][j]
        return f"({bestOrder(i, k)}{bestOrder(k+1, j)})"
    return bestOrder(1, n), dp[1][n]

for _ in range(int(input())):
    n = int(input())
    d = list(map(int, input().split()))

    order, cost = chainedMatrix(d)
    print(order)
    print(cost)


