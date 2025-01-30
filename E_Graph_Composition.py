def count_connected_components(n, edges):
    from collections import defaultdict
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    visited = [False] * (n + 1)
    def dfs(node):
        stack = [node]
        while stack:
            current = stack.pop()
            for neighbor in graph[current]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    stack.append(neighbor)

    components = 0
    for i in range(1, n + 1):
        if not visited[i]:
            visited[i] = True
            dfs(i)
            components += 1
    return components

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    t = int(data[index])
    index += 1
    results = []

    for _ in range(t):
        n = int(data[index])
        m1 = int(data[index + 1])
        m2 = int(data[index + 2])
        index += 3

        edges_F = []
        for _ in range(m1):
            u = int(data[index])
            v = int(data[index + 1])
            index += 2
            edges_F.append((u, v))

        edges_G = []
        for _ in range(m2):
            u = int(data[index])
            v = int(data[index + 1])
            index += 2
            edges_G.append((u, v))

        components_G = count_connected_components(n, edges_G)

        if components_G == 1:
            # G is connected, F must be connected
            results.append(m1 + (n - 1))
        else:
            # G is not connected, F must have the same number of components
            results.append(m1 + components_G - 1)

    for result in results:
        print(result)

# Example usage
solve()
