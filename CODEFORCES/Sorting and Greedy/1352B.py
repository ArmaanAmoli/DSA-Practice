t = int(input())
for _ in range(t):
    n , k = map(int , input().split())
    
    # odd try
    odd_remainder = n - (k-1)
    # even try
    even_remainder = n - 2*(k-1)
    # else No
    
    if(odd_remainder > 0 and odd_remainder%2==1):
        print("YES")
        for i in range(k-1):
            print(1, end=" ")
        print(odd_remainder)
        continue
    elif (even_remainder>0 and even_remainder%2==0):
        print("YES")
        for i in range(k-1):
            print(2 , end=" ")
        print(even_remainder)
    else:
        print("NO")