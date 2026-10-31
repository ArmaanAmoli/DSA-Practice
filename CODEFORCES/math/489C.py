m , s = map(int , input().split())
nums_min = [0]*m
nums_max = [0]*m
if s > 9 * m or (s == 0 and m > 1):
    print("-1 -1")
elif s == 0:
    print("0 0")

else:
    # making the min array
    
    nums_min[0] = 1
    left_over = s - 1
    idx = m - 1
    while(left_over >=9 and idx >= 1):
        nums_min[idx] = 9
        left_over -= 9
        idx-=1
    nums_min[idx] += left_over
    min_num = int("".join(map(str , nums_min)))
    # making max array
    
    left_over = s
    idx = 0
    while(left_over >= 9 and idx < m-1 ):
        nums_max[idx] = 9
        left_over -= 9
        idx+=1
    nums_max[idx] += left_over
    max_num = int("".join(map(str , nums_max)))
    
    print(min_num , max_num)