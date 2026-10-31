import sys

def is_prime(n):
    if n < 2:
        return False
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

def next_prime(n):
    while not is_prime(n):
        n += 1
    return n


data = sys.stdin.buffer.read().split()
t = int(data[0])
out = []
for _ in range(1, t + 1):
    d = int(data[_])
    
    p = next_prime(d+1)
    q = next_prime(p + d)
    out.append(p*q)
print("\n".join(map(str, out)))