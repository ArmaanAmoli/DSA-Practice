num_of_coins = int(input())
coins = list(map(int , input().split()))

coins.sort()
total_sum = 0
for i in coins:
    total_sum+=i

target = total_sum//2
sum = 0
ans = 0
for i in reversed(coins):
    sum+=i
    ans+=1
    if(sum > target):
        break

print(ans)