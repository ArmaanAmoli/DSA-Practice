import sys

input = sys.stdin.readline

n = int(input())
ran = range(10,0,1)
for i in range(n):
    a , b = map(int , input().split())
    if(a==b):
        print(0)
    else:
        diffrence = abs(a-b)
        if(diffrence > 10):
            diff = abs(a-b)
            moves_count = 0
            moves_raw = diff/10;
            moves_count = diff//10;
            if(moves_raw == moves_count):
                print(moves_count)
            else:
                print(moves_count + 1)
        else:
            print(1)
        
