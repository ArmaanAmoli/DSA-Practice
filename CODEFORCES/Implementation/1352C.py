import sys
import math

input = sys.stdin.readline

t = int(input())
for i in range(t):
    n , k = map(int , input().split())
    group_no = math.ceil(k/(n-1) )
    last_multiple_of_n = (group_no-1) * n
    elements_skipped = (group_no-1) * (n-1);
    ans = last_multiple_of_n + (k - elements_skipped);
    print(ans)