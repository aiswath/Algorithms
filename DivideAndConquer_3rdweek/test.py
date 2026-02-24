from collections import deque


nums = [1,2,1,0,4,2,6]
k = 3
res = []
q = deque()
l, r = 0, 0
while r < len(nums):
    while q and nums[q[-1]] < nums[r]:
        q.pop()
    q.append(r)

    if l > q[0]:
        q.popleft()

    if (r + 1) >= k:
        res.append(nums[q[0]])
        l += 1
    r += 1

print(res)