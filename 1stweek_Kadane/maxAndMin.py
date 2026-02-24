for _ in range(int(input())):
    _ = int(input())
    numStr = str(input()).split()
    res = []
    for n in numStr:
        res.append(int(n))
    
        
    print(max(res), min(res))

