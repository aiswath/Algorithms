def change(amount, coins):

    dp = [0] * (amount + 1)
    dp[0] = 1
    
    for i in range(len(coins) -1, -1, -1):
        temp = [0] * (amount + 1)
        temp[0] = 1

        for a in range(1, amount + 1):
            temp[a] = dp[a] 
            if a - coins[i] >= 0:
                temp[a] += temp[a - coins[i]]
        dp = temp
    
    return dp[amount]

for _ in range(int(input())):
    amount = int(input())
    arr = list(map(int, input().split()))
    coins = arr[1:]

    print(change(amount, coins))