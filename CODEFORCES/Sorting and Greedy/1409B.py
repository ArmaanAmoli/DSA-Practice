m = int(input())
for i in range(m):
    a,b,x,y,n = map(int , input().split())
    da = min(n , a-x)
    r = n-da
    db = min(r , b-y)
    p1 = (a-da)*(b-db)
    
    db = min(n , b-y)
    r = n-db
    da = min(r , a-x)
    p2 = (a-da)*(b-db)
    print(min(p1 , p2))