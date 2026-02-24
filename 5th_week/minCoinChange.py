def minCoinChange(amt, coins):
    dp = [amt+1]*(amt+1)
    dp[0] = 0
    coinChosen = [-1]*(amt+1)

    for a in range(1, amt+1):
        for c in coins: # 1, 3, 5
            if a - c >= 0:
                dp[a] = min(dp[a], 1+(dp[a-c]))
                coinChosen[a] = c

    res = []  
    curr = amt 
    while curr > 0:
        coin = coinChosen[curr]
        res.append(coin)
        curr -= coin

    return dp[amt], res

for _ in range(int(input())):
    amt = int(input())
    tmpArr = list(map(int, input().split()))
    coins = tmpArr[1:]
    ways, coins = minCoinChange(amt, coins)
    print(ways, *coins)


