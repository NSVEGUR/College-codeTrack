#TSP Problem using A* algorithm using mst as heuristic
import sys

class MST:
	def __init__(self, V: list, E: list):
		self.V = V
		self.n = len(V)
		self.E = E

	def __min_key__(self, key, mstSet):
		min = sys.maxsize
		for v in range(self.n):
			if key[v] < min and mstSet[v] == False:
				min_index = v
				min = key[v]
		return min_index
	
	def cost(self):
		key = [sys.maxsize]*self.n
		mstSet = [False]*self.n
		key[0] = 0
		for _ in range(self.n):
			u = self.__min_key__(key, mstSet)
			mstSet[u] = True
			for v in range(self.n):
				if self.E[u][v] > 0 and self.E[u][v] < key[v] and mstSet[v] == False:
					key[v] = self.E[u][v]
		return sum(key)

class Graph:
	def __init__(self, V: list, E:list):
		self.V = V
		self.n = len(V)
		self.E = [[0 for _ in range(self.n)] for _ in range(self.n) ]
		self.h = {}
		for edge in E:
			(X,Y, cost) = edge
			if X != Y:
				x, y = self.__index__(X), self.__index__(Y)
				self.E[x][y] = cost
				self.E[y][x] = cost
		self.__calculate_heuristic__()

	def __index__(self, vertex: str) -> int:
		return self.V.index(vertex)
	
	def __calculate_heuristic__(self):
		for index, m in enumerate(self.V):
			V = [v for v in self.V if v != m]
			E = []
			for i,e in enumerate(self.E):
				if i == index:
					continue
				x = e.copy()
				x.pop(index)
				E.append(x)
			mst = MST(V, E)
			self.h[m] = mst.cost()

	def a_star_search(self, s: str):
		open, closed = set([s]), set()
		g = {}
		g[s] = 0
		path_len = 1
		path_costs = []
		while len(open) > 0 and path_len > 0:
			parent_path = None
			for path in open:
				if (path_len == len(path)):
					if parent_path == None or (g[path]+self.h[path[-1]] < g[parent_path] + self.h[parent_path[-1]]):
						parent_path = path
					elif g[path]+self.h[path[-1]] == g[parent_path] + self.h[parent_path[-1]] and g[path] < g[parent_path]:
						parent_path = path
			if parent_path is None:
				path_len -= 1
				continue
			if path_len == self.n:
				path = parent_path + s
				cost = g[parent_path] + self.E[self.__index__(s)][self.__index__(parent_path[-1])]
				print(f"Path: {path}, Cost: {cost}")
				path_costs.append((path, cost))
				path_len -= 1
				closed.add(parent_path)
				open.remove(parent_path)
				continue
			path_len += 1
			closed.add(parent_path)
			for (index, cost) in enumerate(self.E[self.__index__(parent_path[-1])]):
				chosen_path = parent_path + self.V[index]
				if self.V[index] in parent_path:
					continue
				if self.V[index] not in parent_path and (chosen_path not in open or chosen_path not in closed):
					open.add(chosen_path)
					g[chosen_path] = g[parent_path] + cost
				elif chosen_path in open:
					if g[chosen_path] > g[parent_path] + cost:
						g[chosen_path] = g[parent_path] + cost
			open.remove(parent_path)
		minimum = min(path_costs, key=lambda x: x[1])
		print(f"Minimum cost: {minimum[1]} and Path is {minimum[0]}")

if __name__ == '__main__':
	V=['A', 'B', 'C', 'D', 'E']
	E=[
		['A', 'B', 12],
		['A', 'C', 10],
		['A', 'D', 19],
		['A', 'E', 8],
		['B', 'C', 3],
		['B', 'D', 7],
		['B', 'E', 6],
		['C', 'D', 2],
		['C', 'E', 20],
		['D', 'E', 4]
	]
	G = Graph(V, E)
	G.a_star_search("A")