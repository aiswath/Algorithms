t = int(input())

while t > 0:

    s = str(input())
    numStr = s.split()

    nums = []
    for i in range(1, len(numStr)):
        nums.append(int(numStr[i]))

    currSum = nums[0]
    maxSum = nums[0]

    tem, first, sec = 0, 0, 0

    for i in range(1, len(nums)):
        if nums[i] == 0:
            continue
        if currSum + nums[i] < nums[i]:   ### <----*** neglect negative
            currSum = nums[i]
            tem = i                   
        else:
            currSum += nums[i]
        
        if currSum > maxSum:              
            maxSum = currSum
            first = tem                   ### <--- update index
            sec = i
    
    if maxSum < 0:
        print(0, -1, -1)
    else:
        print(maxSum, first, sec)

    t -= 1