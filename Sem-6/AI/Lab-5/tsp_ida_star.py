#TSP Problem using ida*(ID-DFS, Iterative deepening depth first search) algorithm using mst as heuristic


import sys


class MST:
	def __init__(self, V:list, E:list):
		self.V = V
		self.n = len(V)
		self.E = E
	
	def __min_key__(self, key:list, mstSet:list):
		min = sys.maxsize
		for i in range(self.n):
			if key[i] < min and mstSet[i] == False:
				min_index = i
				min = key[i]
		return min_index

	def cost(self):
		key = [sys.maxsize]*self.n
		mstSet = [False]*self.n

		key[0] = 0
		for _ in range(self.n):
			u = self.__min_key__(key, mstSet)
			mstSet[u] = True
			for v in range(self.n):
				if not mstSet[v] and self.E[u][v] and key[v] > self.E[u][v]:
					key[v] = self.E[u][v]
		return sum(key)

class Graph:
	def __init__(self, V:list, E:list[tuple]):
		self.V = V
		self.n = len(V)
		self.E = [[0 for _ in range(self.n)] for _ in range(self.n)]
		for edge in E:
			(X, Y, cost) = edge
			if X != Y:
				x, y = self.__index__(X), self.__index__(Y)
				self.E[x][y] = cost
				self.E[y][x] = cost
		self.h = {}
		self.__calculate_heuristics__()

	def __index__(self, vertex:str):
		return self.V.index(vertex)
	
	def __calculate_heuristics__(self):
		for index, vertex in enumerate(self.V):
			V = [v for v in self.V if v != vertex]
			E = []
			for (i, e) in enumerate(self.E):
				if i == index:
					continue
				x = e.copy()
				x.pop(index)
				E.append(x)
			self.h[vertex] = MST(V, E).cost()
		

	def ida_star_search(self, start: tuple):
		cutoff_bound = {}
		cutoff_bound = self.h[start[0]]
		explored = []
		while True:
			stack = []
			stack.append(start)
			paths = []
			while stack:
				backtrack = False
				path, cost = stack.pop()
				f = cost + self.h[path[-1]]
				if path not in explored and f > cutoff_bound:
					backtrack = True
					explored.append(path)
				elif f > cutoff_bound:
					continue
				if len(path) == self.n:
					goal_path = path + start[0]
					goal_cost = cost + self.E[self.__index__(path[-1])][self.__index__(start[0])]
					print(f"Path: {goal_path}, Cost: {goal_cost}")
					paths.append((goal_path, goal_cost))
				for (neighbor_index, neighbor_cost) in enumerate(self.E[self.__index__(path[-1])]):
					neighbor = self.V[neighbor_index]
					if neighbor_cost and neighbor not in path:
						stack.append((path + neighbor, cost + neighbor_cost))
				if backtrack:
					min_cost = None
					min_path = None
					for (current_path, current_cost) in stack:
						if len(current_path) > len(path):
							if min_cost == None or (current_cost + self.h[current_path[-1]] < min_cost + self.h[min_path[-1]]):
								min_cost = current_cost
								min_path = current_path
							elif current_cost + self.h[current_path[-1]] == min_cost + self.h[min_path[-1]] and current_cost < min_cost:
								min_cost = current_cost
								min_path = current_path
					if min_cost != None and min_cost + self.h[min_path[-1]] > cutoff_bound:
						cutoff_bound = min_cost + self.h[min_path[-1]]
						break

			if paths:
				minimum = min(paths, key = lambda x: x[1])
				print(f"Minimum Cost: {minimum[1]} and its Path: {minimum[0]}")
			if not stack:
				break


if __name__ == '__main__':
	V=['A', 'B', 'C', 'D']
	E=[
		['A', 'B', 10],
		['A', 'C', 15],
		['A', 'D', 20],
		['B', 'C', 35],
		['B', 'D', 25],
		['C', 'D', 30]
	]
	G = Graph(V, E)
	G.ida_star_search(("A", 0))
