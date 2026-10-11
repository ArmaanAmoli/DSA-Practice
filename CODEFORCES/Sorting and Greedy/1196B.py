answer = []
sum = 0
def solve(l:list[int] , k:int , idx:int , sum:int , ans:list[int]):
    if(idx >= n):
        if(sum%2 != 0):
            
    
    sum += l[idx]
    if(sum%2 == 0):
        solve(l , k , idx+1 , sum , ans )
    else:
        
    

t = int(input())
for _ in range(t):
    n , k = (map(int , input().split()))
    l = list(map(int , input().split()))
    ans_list = []
    j = 0
    for j,i in enumerate( l , start=1):
        if(i%2 != 0):
            #create sepration
            ans_list.append(j)