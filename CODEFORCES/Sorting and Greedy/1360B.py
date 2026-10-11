m = int(input())
for i in range(m):
    n = int(input())
    ath = list(map(int , input().split()))
    ath.sort()
    ans = ath[len(ath)-1]
    for i in range(n-1):
        diff = ath[i+1] - ath[i]
        ans = min(diff , ans)
    print(ans)