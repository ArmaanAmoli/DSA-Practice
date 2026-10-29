# import math

# def solve(n):
#     if(n==1):
#         return "NO"
#     root = math.ceil(math.sqrt(n))
#     factors = set()

#     factors.add(1)
#     factors.add(n)

#     for i in range(2,root+1):
#         if(n%i==0):
#             factors.add(i)
#             factors.add(n/i)
#             if(len(factors)>3):
#                 return "NO"
#     return "YES" if len(factors)==3 else "NO"

# t = int(input())
# nums = list(map(int , input().split()))

# for _ in nums:
#     print(solve(_))

# OPTIMAL

import sys
from math import isqrt


def main():
    data = sys.stdin.buffer.read().split()
    n = int(data[0])

    LIMIT = 10**6
    is_prime = bytearray([1]) * (LIMIT + 1)
    is_prime[0] = is_prime[1] = 0

    for i in range(2, isqrt(LIMIT) + 1):
        if is_prime[i]:
            is_prime[i * i :: i] = bytearray(len(range(i * i, LIMIT + 1, i)))

    out = []
    for k in range(1, n + 1):
        x = int(data[k])
        r = isqrt(x)
        out.append("YES" if r * r == x and is_prime[r] else "NO")

    print("\n".join(out))


main()
