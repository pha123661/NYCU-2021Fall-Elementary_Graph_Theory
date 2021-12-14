from itertools import combinations
from collections import deque
def ifK5(graph):
    n = len(graph)
    for points in combinations(range(n), 5):
        flag = True
        for u,v in combinations(points, 2):
            if graph[u][v] == 0:
                flag = False
                break
        if flag:
            return True
    return False

def ifK33(graph):
    def isK33(points):
        avai = list(combinations(points, 3))[:10]
        points = set(points)
        for g1 in avai:
            flag = True
            g1 = set(g1)
            g2 = points-g1

            for u in g1:
                for v in g2:
                    if graph[u][v] == 0:
                        flag=False
                        break
            if flag:
                return True
        return False


    n = len(graph)
    for points in combinations(range(n), 6):
        if isK33(points):
            return True
    return False


def main():
    n, m = map(int, input().split())
    graph = [[0]*n for _ in range(n)]

    for _ in range(m):
        u, v = map(lambda x: int(x)-1, input().split())
        graph[u][v] = graph[v][u] = 1
    
    # K5
    K5_FLAG = ifK5(graph)

    # K33
    K3_FLAG = ifK33(graph)

    if K3_FLAG and K5_FLAG:
        print(3)
    elif K3_FLAG:
        print(1)
    elif K5_FLAG:
        print(2)
    else:
        print(0)
    



if __name__ == '__main__':
    main()