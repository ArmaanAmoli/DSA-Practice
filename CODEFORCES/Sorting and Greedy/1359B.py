import sys

input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n , m , x , y = map(int , input().split());
    grid = [input().strip() for _ in range(n)]
    
    cost = 0
    for i in range(n):
        j=0
        while j < m:
            tile = grid[i][j]
            if(tile == '.'):
                if(j< m-1 and grid[i][j+1]=='.' and y < 2*x):
                    cost+=y
                    j= j + 1
                else:
                    cost+=x
            j+=1
    print(cost)