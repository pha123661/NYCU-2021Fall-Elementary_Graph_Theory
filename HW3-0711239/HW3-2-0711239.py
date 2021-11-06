parents = None
rank = None

def find(x):
    global parents, rank
    if parents[x] == x:
        return x
    parents[x] = find(parents[x])
    return parents[x]

def unite(x, y):
    global parents, rank
    if rank[x] < rank[y]:
        parents[x] = y
    else:
        parents[y] = x
        if rank[x] == rank[y]:
            rank[x] += 1

def init():
    global parents, rank
    parents = list(range(n))
    rank = [0]*n

def main():
    global n
    n, m = map(int, input().split())
    edges = list()
    for _ in range(m):
        u, v, w = map(int, input().split())
        edges.append((u-1, v-1, w))
    edges.sort(key=lambda x: x[2])

    ans = 0
    init()
    mst_edge = list()
    for idx, edge in enumerate(edges):
        x, y = find(edge[0]), find(edge[1])
        if x != y: # not cycle
            unite(x, y)
            ans += edge[2]
            mst_edge.append(idx)

    unique = True
    for edge_idx in mst_edge: # for every edge added in MST
        init()
        ans2 = 0
        edge_num = 0
        for idx in range(m):
            if idx == edge_idx: # "delete" this edge from graph
                continue
            x, y = find(edges[idx][0]) , find(edges[idx][1])
            if x != y: # not cycle
                unite(x, y)
                ans2 += edges[idx][2]
                edge_num += 1
            if edge_num != len(mst_edge):
                continue
            if ans2 == ans:
                unique = False
                break
        if not unique:
            break
    print(ans)
    print("YES" if unique else "NO")





if __name__ == "__main__":
    main()