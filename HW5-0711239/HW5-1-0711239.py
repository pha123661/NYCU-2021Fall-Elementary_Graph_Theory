import copy
INT_MAX = 2**64

def minimum_cycle(adj, n):
    dist = copy.deepcopy(adj)
    ans = INT_MAX
    assert n == len(adj), "FUCK"
    for k in range(n):
        for i in range(k):
            for j in range(k):
                if i == j:
                    continue
                ans = min(ans, adj[k][i]+dist[i][j]+adj[j][k])
        
        for i in range(n):
            for j in range(n):
                if adj[i][k] != INT_MAX and adj[k][j] != INT_MAX:
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j])

    if ans >= INT_MAX:
        return -1
    else:
        return ans

def main():
    n, e, directed = map(int, input().split())
    adj = [[INT_MAX for _ in range(n)] for _ in range(n)]
    if directed == 0:
        for _ in range(e):
            u, v, w = map(int, input().split())
            u -= 1
            v -= 1
            adj[u][v] = w
            adj[v][u] = w
    else:
        for _ in range(e):
            u, v, w = map(int, input().split())
            u -= 1
            v -= 1
            adj[u][v] = w

    print(minimum_cycle(adj, n))

if __name__ == '__main__':
    main()