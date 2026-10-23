t = int(input())
for _ in range(t):
    n = int(input())
    xs = []
    ys = []
    for _ in range(n):
        xi, yi = map(int, input().split())
        xs.append(xi)
        ys.append(yi)
    xs.sort()
    ys.sort()

    if n % 2 == 1:
        print(1)
    else:
        k = n // 2
        range_x = xs[k] - xs[k - 1] + 1
        range_y = ys[k] - ys[k - 1] + 1
        print(range_x * range_y)