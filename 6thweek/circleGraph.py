import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def find(x, parent):
    if parent[x] != x:
        parent[x] = find(parent[x], parent)
    return parent[x]

def union(a, b, parent):
    ra, rb = find(a, parent), find(b, parent)
    if ra == rb:
        return False 
    parent[rb] = ra
    return True

t = int(input().strip())

for _ in range(t):
    n, m = map(int, input().split())
    parent = [i for i in range(n + 1)]
    seen = set()
    cycle = False

    for _ in range(m):
        u, v = map(int, input().split())
        if u == v:
            continue 
        e = (min(u, v), max(u, v))
        if e in seen:
            continue  
        seen.add(e)
        if not union(u, v, parent):  
            cycle = True

    print(1 if cycle else 0)
