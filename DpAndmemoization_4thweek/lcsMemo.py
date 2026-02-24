def lcs(i, j, s1, s2):
    memo = {}
    def dfs(i, j):
        
        if i == len(s1) or j == len(s2):
            return 0
        
        if(i, j) in memo:
            return memo[(i, j)]
        
        if s1[i] == s2[j]:
            memo[(i, j)] = 1 + dfs(i + 1, j + 1)
        else:
            memo[(i, j)] = max(dfs(i + 1, j), dfs(i, j+1))
        return memo[(i, j)]
    return dfs(0, 0)
        
                
for _ in range(int(input())):
    s1, s2 = map(str, input().split())
    print(lcs(0, 0, s1,s2))