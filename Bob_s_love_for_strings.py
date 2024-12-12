class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
    
    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])  # Path compression
        return self.parent[u]
    
    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        
        if root_u != root_v:
            # Union by rank
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

def can_connect(s1, s2):
    # Function to check if two strings differ by exactly one letter
    diff_count = 0
    for c1, c2 in zip(s1, s2):
        if c1 != c2:
            diff_count += 1
            if diff_count > 1:
                return False
    return diff_count == 1

def solve(tokens):
    n = len(tokens)
    uf = UnionFind(n)
    
    # Check all pairs of strings and union if they differ by exactly one letter
    for i in range(n):
        for j in range(i + 1, n):
            if can_connect(tokens[i], tokens[j]):
                uf.union(i, j)
    
    # Count the sizes of the connected components
    component_sizes = {}
    for i in range(n):
        root = uf.find(i)
        if root not in component_sizes:
            component_sizes[root] = 0
        component_sizes[root] += 1
    
    # Get the number of clusters and the size of the largest cluster
    num_clusters = len(component_sizes)
    largest_cluster_size = max(component_sizes.values())
    
    return num_clusters, largest_cluster_size

# Example usage:
tokens = ["abc", "abd", "bcd", "xyz", "xyy", "zzz"]
num_clusters, largest_cluster_size = solve(tokens)
print(num_clusters, largest_cluster_size)
