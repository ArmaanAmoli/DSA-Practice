import sys

input = sys.stdin.readline

n = int(input())

for i in range(n):
    a , b = map(int , input().split())
    if(a<b):
        print(b-a)
    elif(a%b == 0):
        print(0)
    elif(a%b != 0):
        print((((a//b)+1)*b) - a )
