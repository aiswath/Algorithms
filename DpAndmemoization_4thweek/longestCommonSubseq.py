def longestCommonSubseq(s1, s2):
    
    m, n = len(s1), len(s2)
    dp = [[0]* (n+1) for _ in range(m+1)]

    for i in range(m-1, -1, -1):  
        for j in range(n-1, -1, -1): 
            if s1[i] == s2[j]:
                dp[i][j] = 1 + dp[i+1][j+1]
            
            else:
                dp[i][j] = max(dp[i+1][j], dp[i][j+1])
    
    i, j = 0, 0        
    res = []
    while i < m and j < n:  
        if s1[i] == s2[j]:
            res.append(s1[i])
            i += 1
            j += 1
        elif dp[i+1][j] >= dp[i][j+1]:
            i += 1
        else:
            j += 1
    
    return dp[0][0], "".join(res)


for _ in range(int(input())):

    stringArr = str(input()).split()
    str1, str2 = stringArr[0], stringArr[1]

    length, string = longestCommonSubseq(str1, str2)
    print(length, string)



               