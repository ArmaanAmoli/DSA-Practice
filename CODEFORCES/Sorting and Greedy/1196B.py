# answer:list[list[int]] = []
# def solve(nums:list[int] , breaks_left:int , idx:int , sum:int , ans:list[int]):
#     if(idx == len(nums)-1 and breaks_left == 0):
#         num = nums[len(nums)-1];
#         if((sum+num)%2 == 0):return;
#         ans.append(idx+1)
#         # print(ans)
#         answer.append(ans.copy());
#         return;
#     if(idx == len(nums)-1):
#         return
#     sum += nums[idx]
#     if(sum%2 == 0):
#         solve(nums , breaks_left , idx+1 , sum , ans)
#     else:
#         if(breaks_left > 0):
#             ans.append(idx+1)
#             solve(nums , breaks_left-1 , idx+1 , 0, ans)
#             ans.pop()
    
#     sum-=nums[idx]
#     return;
    

t = int(input())
for _ in range(t):
    n , k = (map(int , input().split()))
    l = list(map(int , input().split()))
    # answer.clear()
    # solve(l , k-1 , 0 , 0 , [])
    # if(len(answer)==0):
    #     print("NO")
    # else:
    #     print("YES")
        
    odds = 0
    for _ in l:
        if _%2!=0:
            odds+=1
    
    if(odds >=k and ((odds-k)%2 ) == 0):
        odds_collected = 0
        ans = []
        for [idx , _] in enumerate(l , start=0):
            if _ % 2 != 0:
                odds_collected+=1
                if(odds_collected<k):
                    ans.append(idx+1)
        
        ans.append(len(l))
        print("YES")
        for _ in ans:
            print(_," " , end="")
        print()
    else:
        print("NO")