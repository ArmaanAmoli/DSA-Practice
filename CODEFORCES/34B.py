n , m = map(int , input().split())
tvs = list(map(int , input().split()))
ans = 0
j = 0
tvs.sort()
for tv in tvs:
    if(tv<0 and j<m):
        ans+=tv
        j+=1
    else:
        break

print(ans*-1)
