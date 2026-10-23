import math

t = int(input())
for _ in range(t):
    n,k = map(int , input().split())
    st = str(input())
    s = "".join(sorted(st))
    if(s[k-1] == s[0]):
        if(k==n):
            print(s[0])
        elif(s[k] == s[n-1]):
            #distribute
            l = ((n-1) - k) + 1
            m = math.ceil(l/k)
            print(s[k-1] + s[k]*m)
        else:
            print(s[k-1:])
    else:
        print(s[k-1])