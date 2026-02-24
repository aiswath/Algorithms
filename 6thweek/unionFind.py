import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    x, y = find(x), find(y)
    if x == y: return
    if rank[x] < rank[y]:
        x, y = y, x
    parent[y] = x
    rank[x] += rank[y]

def makeFriend(x, y):
    if find(x) == find(y+n):
        print(0); return
    union(x, y)
    union(x + n, y + n)

def makeEnemy(x, y):
    if find(x) == find(y):
        print(0); return
    union(x, y+n)
    union(x+n, y)

def query(x, y):
    if find(x) == find(y):
        print(1)
    elif find(x) == find(y+n):
        print(2)
    else:
        print(3)

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    parent = list(range(2 * n))
    rank = [0]* (2*n)
    for _ in range(m):
        q, x, y = map(int, input().split())
        if q == 1: makeFriend(x, y)
        elif q == 2: makeEnemy(x, y)
        else: query(x, y)