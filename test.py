def min_range(n, a, b, c):
    min_val = min(c)
    max_val = max(c)

    if a * b > 0:
        return max_val - min_val

    target = (min_val + max_val) // 2
    min_diff = float('inf')
    for num in c:
        min_diff = min(min_diff, abs(num - target))

    return min_diff

t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())
    c = list(map(int, input().split()))
    print(min_range(n, a, b, c))