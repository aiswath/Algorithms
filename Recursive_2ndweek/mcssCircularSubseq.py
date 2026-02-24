def mcss(nums) :
    globMin, globMax = nums[0], nums[0]
    curMin, curMax, total = 0, 0, 0

    for num in nums :
        total += num
        curMin = min(curMin + num, num)
        curMax = max(curMax + num, num)
        
        globMin = min(globMin, curMin)
        globMax = max(globMax, curMax)

    return max(globMax, total -  globMin) if globMax > 0 else 0

for _ in range(int(input())) :
    _ = input()
    arr = list(map(int, input().split()))
    print(mcss(arr))