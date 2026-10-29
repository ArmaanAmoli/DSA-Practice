n = int(input())

def find_if_almost_prime(n):
    factors = set()
    
    while n%2 == 0:
        factors.add(2)
        n//=2
    
    factor = 3
    while factor * factor <= n:
        while n % factor == 0:
            n//=factor
            factors.add(factor)
            if(len(factors) >= 3):
                return False
        factor += 2
    
    if n>2:
        factors.add(n)
    
    return len(factors)==2

ans = 0
for _ in range(1 , n+1):
    if(find_if_almost_prime(_)):
        ans+=1

print(ans)