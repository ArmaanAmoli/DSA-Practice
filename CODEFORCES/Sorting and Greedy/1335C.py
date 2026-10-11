t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    if n == 1:
        print(0)
        continue
    d = {}
    max_f = 0
    n_uniq = 0
    for i in l:
        if i not in d:
            d[i] = 1
            n_uniq += 1
            max_f= max(max_f , 1)
        else:
            d[i] += 1
            max_f = max(max_f, d[i])
    if n_uniq > max_f:
        print(max_f)
    elif n_uniq < max_f:
        print(n_uniq)
    else:
        print(n_uniq - 1)
