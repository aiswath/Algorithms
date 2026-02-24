def cc(amt, coins):
    
    dp = [0]*(amt+1)
    dp[0] = 1

    for i in range(len(coins) - 1, -1, -1):
        tmp = [0]*(amt+1)
        tmp[0] = 1
        for a in range(1, amt+1):
            tmp[a] = dp[a]
            if ( a - coins[i]) >= 0:
                tmp[a] += tmp[a-coins[i]]

        dp = tmp

    return dp[amt]


for _ in range(int(input())):
    amt = int(input())
    tmp = list(map(int, input().split()))
    coins = tmp[1:]

    print(cc(amt, coins))