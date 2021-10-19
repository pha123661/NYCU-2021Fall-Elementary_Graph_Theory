from itertools import  product, permutations
def main():
    n, e, k = map(int, input().split())
    colors = [list() for _ in range(k)]# colors[color] = list of cities
    for city, color in enumerate(map(int, input().split())):
        color -= 1
        colors[color].append(city)
    dist = [[2**32]*n for _ in range(n)]
    for _ in range(e):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        dist[u][v] = w
        dist[v][u] = w
    
    min_cost = 2**32
    for to_be_visited in product(*colors):
        for shunxu in permutations(to_be_visited):
            # calculate cost
            cost = 0
            for i in range(1, len(shunxu)):
                cost += dist[shunxu[i-1]][shunxu[i]]
            min_cost = min(cost, min_cost)
    print(min_cost)


if __name__ == '__main__':
    main()