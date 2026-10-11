import sys

input = sys.stdin.readline
ans = 0
for r in range(5):
    row = list(map(int , input().split()))
    
    if 1 in row:
        c = row.index(1)
        ans = (abs(r-2) + abs(c-2))

print(ans)