import math
t = int(input())
for _ in range(t):
    n = int(input())
    # i = 2
    k = 0
    ans = []
    d = {}
    for i in range(2,math.ceil(math.sqrt(n))):
        if(n%i==0):
            n = n//i
            ans.append(i)
            d[i] = 1
            i+=1
            k+=1
            if(k==2):
                if(n not in d and n>1): 
                    ans.append(n)
                break
        if(i > n):break;
    
    if len(ans) == 3:
        print("YES")
        for _ in ans:
            print(_ , end=" ")
        print()
    else:
        print("NO")