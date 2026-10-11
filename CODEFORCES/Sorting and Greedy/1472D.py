m = int(input())
for i in range(0, m):
    n = int(input())
    nums = list(map(int, input().split()))
    nums.sort()
    nums.reverse()
    odd = []
    even = []
    for num in nums:
        if num % 2 == 0:
            even.append(num)
        else:
            odd.append(num)

    alice = 0
    bob = 0
    isAliceTurn = True
    op = 0
    ep = 0
    while op < len(odd) and ep < len(even):
        o = odd[op]
        e = even[ep]
        if isAliceTurn:
            if o > e:
                op += 1
            else:
                alice += e
                ep += 1
        else:
            if o < e:
                ep += 1
            else:
                bob += o
                op += 1
        isAliceTurn = not isAliceTurn
    while op < len(odd):
        if not isAliceTurn:
            bob += odd[op]
        op += 1
        isAliceTurn = not isAliceTurn
    while ep < len(even):
        if isAliceTurn:
            alice += even[ep]
        ep += 1
        isAliceTurn = not isAliceTurn
        

    if(alice>bob):
        print("Alice")
    elif(bob>alice):
        print("Bob")
    else:
        print("Tie")