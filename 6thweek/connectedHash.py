def find(x, parent):
    if parent[x] != x:
        parent[x] = find(parent[x], parent)
    return parent[x]

def union(x, y, parent, size):
    x, y = find(x, parent), find(y, parent)
    if x == y:
        return
    if size[x] < size[y]:
        x, y = y, x
    parent[y] = x
    size[x] += size[y]

def longestPath(board):
    rows, cols = len(board), len(board[0])
    n = rows * cols

    parent = [i for i in range(n)]
    size = [1] * n

    def idx(r, c):
        return r * cols + c

    directions = [(1,0), (-1,0), (0,1), (0,-1)]

    
    for r in range(rows):
        for c in range(cols):
            if board[r][c] == '#':
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] == '#':
                        union(idx(r, c), idx(nr, nc), parent, size)

    
    seen = set()
    maxLen = 0
    for r in range(rows):
        for c in range(cols):
            if board[r][c] == '#':
                root = find(idx(r, c), parent)
                if root not in seen:
                    seen.add(root)
                    maxLen = max(maxLen, size[root])
    return maxLen

for _ in range(int(input())):
    r, c = map(int, input().split())
    board = [list(input().strip()) for _ in range(r)]
    print(longestPath(board))
