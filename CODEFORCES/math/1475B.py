import sys

data = sys.stdin.buffer.read().split()
t = data[0]
for _ in range(1 , len(data)):
    num = int(data[_])
    if(num%2021 == 0 or num%2020==0):
        print("YES")
    elif(num < 2020):
        print("NO")
    
    else:
        n = 1+(num//2021)
        m = 0
        
        iters = (n*2021 + m*2020) - num
        m+=iters
        n-=iters
        
        if(n<0):
            print("NO")
        
        else:
            print("YES")
            