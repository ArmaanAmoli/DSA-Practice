
def find_digit_sum(n:int)->int :
    return sum(map(int , str(n)))

def decrease_sum(n , s):
    p = 10
    while True:
        m = ((n + (p - 1))//p) * p
        
        if(find_digit_sum(m) <= s):
            return (m-n)

        p *= 10
        
t = int(input())
for _ in range(t):
    n , s = map(int , input().split())
    
    if(find_digit_sum(n) <=s):
        print(0)
    else:
        print(decrease_sum(n , s))
    