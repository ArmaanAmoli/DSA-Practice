n , k = map(int , input().split())
nums = list(map(int , input().split()))
limit = 1000000000
nums.sort()
if(k==0):
    if(1<=nums[0]-1<=limit):
        print(nums[0]-1)
    else:
        print(-1)
elif(k==n):
    num = nums[n-1]
    if(1<=num<=limit):
        print(num)
    else:
        print(-1)
else:
    num1 = nums[k-1]
    num2 = nums[k]
    if ((num1 == num2) or ( not(1<=num1<=limit))):
        print(-1)
    else:
        print(num1)