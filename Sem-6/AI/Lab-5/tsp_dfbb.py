#TSP Problem using DFBB(Depth first branch and bound) algorithm using mst as heuristic

import sys

class State:
	def __init__(self, path:str, cost:int):
		self.path = path
		self.cost = cost

class MST:
	def __init__(self, V:list[str], E:list):
		self.V = V
		self.n = len(V)
		self.E = E
	
	def __min_key__(self, key, mstSet):
		min = sys.maxsize
		for i in range(self.n):
			if key[i] < min and mstSet[i] == False:
				min = key[i]
				min_index = i
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
	def __init__(self, V:list[str], E:list):
		self.V = V
		self.n = len(V)
		self.E = [[0 for _ in range(self.n)] for _ in range(self.n)]
		self.h = {}
		for edge in E:
			(X, Y, cost) = edge
			if X != Y:
				x, y = self.__index__(X), self.__index__(Y)
				self.E[x][y] = cost
				self.E[y][x] = cost
		self.__calculate_heuristic__()
	
	def __index__(self, vertex: str):
		return self.V.index(vertex)

	def __calculate_heuristic__(self):
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
	
	def dfbb_search(self, start_state: State):
		best_cost = sys.maxsize
		stack: list[State] = []
		stack.append(start_state)
		paths = []
		while stack:
			state = stack.pop()
			f = state.cost + self.h[state.path[-1]]
			if f >= best_cost:
				continue
			if len(state.path) == self.n:
				path = state.path + start_state.path
				cost = state.cost + self.E[self.__index__(state.path[-1])][self.__index__(start_state.path)]
				paths.append(State(path, cost))
				print(f"Path: {path}, Cost: {cost}")
				f = state.cost + self.h[state.path[-1]]
				if f < best_cost:
					best_cost = f
				continue
			for (neighbor_index, neighbor_cost) in enumerate(self.E[self.__index__(state.path[-1])]):
				neighbor = self.V[neighbor_index]
				if neighbor_cost and neighbor not in state.path:
					stack.append(State(state.path + neighbor, state.cost + neighbor_cost))
		minimum = min(paths, key = lambda x: x.cost)
		print(f"Minimum cost: {minimum.cost} and Path is {minimum.path}")

if __name__ == "__main__":
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
	G.dfbb_search(State("A", 0))