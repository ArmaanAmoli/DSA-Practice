import sys

input = sys.stdin.readline
strs = [];
for i in range(2):
    r = str(input())
    strs.append(r)
l = len(strs[0])
ans = 0
if(str(strs[0]).lower() == str(strs[1]).lower()):
    print(0)
else:
    for i in range(l):
        c1 , c2 = str(strs[0][i]) , str(strs[1][i])
        i1 = ord(c1.lower())
        i2 = ord(c2.lower())
        if(i1>i2):
            print(1)
            break
        elif(i1<i2):
            print(-1)
            break
    