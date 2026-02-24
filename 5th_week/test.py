from functools import lru_cache

trans = ['abc','cde'] 
ans = ['bca','ecd']   
n = len(trans)
def minSwaps(n, trans, ans):
    trans = list(trans)
    ans = list(ans)

    def dfs(s):
        s = list(s)
        i = 0
        while i < n and s[i] == ans[i]:
            i += 1
        
        if i == n:
            return 0
        res = float('inf')

        for j in range(i + 1, n):
            if s[j] == ans[i] and s[j] != ans[j]:
                s[i], s[j] = s[j], s[i]
                res = min(res, 1 + dfs(tuple(s)))
                s[i], s[j] = s[j], s[i]
        return res
    return dfs(tuple(trans))
def minSwapList(n, trans, ans):
    total = 0
    for i in range(n):
        total += minSwaps(n, trans[i], ans[i])
    return total
print(minSwapList(n, trans, ans))
# def minSwap(n, trans, ans):
#     if sorted(trans) != sorted(ans):
#         return -1

#     trans = list(trans)
#     swaps = 0
#     for i in range(len(trans)):
#         if trans[i] != ans[i]:
#             for j in range(i + 1, len(trans)):
#                 if trans[j] == ans[i]:
#                     trans[i], trans[j] = trans[j], trans[i]
#                     swaps += 1
#                     break
#     return swaps
    


# print(minSwapList(n, trans, ans))


