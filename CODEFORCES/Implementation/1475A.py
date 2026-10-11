import math
import sys

input = sys.stdin.readline

n = int(input())
ran = range(10, 0, 1)
for i in range(n):
    a = int(input())
    if a % 2 != 0:
        print("YES")
    else:
        l = math.log2(a)
        lf = math.floor(l)
        if l == lf:
            print("NO")
        else:
            print("YES")
