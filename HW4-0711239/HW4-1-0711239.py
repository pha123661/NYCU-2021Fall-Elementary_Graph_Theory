from collections import defaultdict

class graph:
	def __init__(self, v) -> None:
		self.vnum = v
		self.g = defaultdict(list)

	def add_edge(self, u, v):
		self.g[u].append(v)
		self.g[v].append(u)

	def dfs_util(self, x):
		self.visited[x] = True
		for u in self.g[x]:
			if not self.visited[u]:
				self.dfs_util(u)
				if not self.seleted[u]:
					self.seleted[x] = True
				

	def cardinality_vertex_set(self):
		self.visited = [False]*self.vnum
		self.seleted = [False]*self.vnum
		self.dfs_util(0)
		sum = 0
		for b in self.seleted:
			if b:
				sum += 1
		return sum

def main():
    n = int(input())
    cost = list(map(int, input().split()))
    g = graph(n)
    for _ in range(n-1):
        u, v = map(int, input().split())
        u, v = u-1, v-1
        g.add_edge(u, v)
    ans = g.cardinality_vertex_set()
    print(f"{ans} {ans}")

if __name__ == '__main__':
    main()