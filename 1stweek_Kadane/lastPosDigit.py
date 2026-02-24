
t = int(input())
for _ in range(t):
    s = str(input())
    nums = s.split()
    res = 1
    for c in nums[1:]:
        lastDigit = int(c) % 10
        res = (lastDigit * res) % 10
    print(res)