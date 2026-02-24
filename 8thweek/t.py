import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

def preTopost(arr, l, r):
    if l > r:
        return []
    
    root = arr[l]
    m = l+1

    
    while m <= r and arr[m] < root:
        m += 1

    left = preTopost(arr, l+1, m-1)
    right = preTopost(arr, m, r)

    return left + right + [root]


def postTopre(arr, l, r):
    if l > r:
        return []
    
    root = arr[r]
    m = r-1


    while m >= l and arr[m] > root:
        m -= 1

    left = postTopre(arr, l, m)
    right = postTopre(arr, m+1, r-1)

    return [root] + left + right


t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    if k == 1:
        res = preTopost(arr, 0, n-1)
        print(*res)
    else:
        res = postTopre(arr, 0, n-1)
        print(*res)
