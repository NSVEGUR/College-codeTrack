#TRAVELING SALESMAN PROBLEM USING MST AS HEURISTIC
#1. A* ALGORITHM
#2. DFBB ALGORITHM
#3. IDA* ALGORITHM

import sys

class MST:
	def __init__(self, V: list, E:list[list]):
		self.V = V
		self.n = len(V)
		self.E = E
	
	def __min_key__(self, key: list, mstSet:list):
		min = sys.maxsize
		for i in range(self.n):
			if not mstSet[i] and key[i] < min:
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
			for (index, cost) in enumerate(self.E[u]):
				if cost and not mstSet[index] and key[index] > cost:
					key[index] = cost
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
				if index == i:
					continue
				x = e.copy()
				x.pop(index)
				E.append(x)
			self.h[vertex] = MST(V, E).cost()

	#A* Algorithm
	def a_star_search(self, s:tuple):
		print("\n----- TSP using A* algorithm (MST as Heuristic) -----\n")
		s = s[0]
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
				goal_path = parent_path + s
				goal_cost = g[parent_path] + self.E[self.__index__(s)][self.__index__(parent_path[-1])]
				print(f"Path: {goal_path}, Cost: {goal_cost}")
				path_costs.append((goal_path, goal_cost))
				path_len -= 1
				closed.add(parent_path)
				open.remove(parent_path)
				continue
			path_len += 1
			closed.add(parent_path)
			for (index, cost) in enumerate(self.E[self.__index__(parent_path[-1])]):
				chosen_path = parent_path + self.V[index]
				if self.V[index] not in parent_path and (chosen_path not in open or chosen_path not in closed):
					open.add(chosen_path)
					g[chosen_path] = g[parent_path] + cost
				elif chosen_path in open:
					if g[chosen_path] > g[parent_path] + cost:
						g[chosen_path] = g[parent_path] + cost
			open.remove(parent_path)
		minimum = min(path_costs, key=lambda x: x[1])
		print(f"\nMinimum cost: {minimum[1]} and its Path is {minimum[0]}\n")

	#DFBB Algorithm
	def dfbb_search(self, s: tuple):
		print("\n----- TSP using DFBB algorithm (MST as Heuristic) -----\n")
		best_cost = sys.maxsize
		stack = []
		stack.append(s)
		paths = []
		while stack:
			path, cost = stack.pop()
			f = cost + self.h[path[-1]]
			if f >= best_cost:
				continue
			if len(path) == self.n:
				goal_path = path + s[0]
				goal_cost = cost + self.E[self.__index__(path[-1])][self.__index__(s[0])]
				paths.append((goal_path, goal_cost))
				print(f"Path: {goal_path}, Cost: {goal_cost}")
				f = cost + self.h[path[-1]]
				if f < best_cost:
					best_cost = f
				continue
			for (neighbor_index, neighbor_cost) in enumerate(self.E[self.__index__(path[-1])]):
				neighbor = self.V[neighbor_index]
				if neighbor_cost and neighbor not in path:
					stack.append((path + neighbor, cost + neighbor_cost))
		minimum = min(paths, key = lambda x: x[1])
		print(f"\nMinimum cost: {minimum[1]} and its Path is {minimum[0]}\n")

	#IDA* Algorithm
	def ida_star_search(self, s:tuple):
		print("\n----- TSP using IDA* algorithm (MST as Heuristic) -----\n")
		cutoff_bound = self.h[s[0]]
		explored = [] 
		best_bound = None
		while True:
			stack = []
			stack.append(s)
			paths = []
			while stack:
				backtrack = False
				path, cost = stack.pop()
				f = cost + self.h[path[-1]]
				if best_bound != None and f > best_bound:
					continue
				if path not in explored and f > cutoff_bound:
					backtrack = True
					explored.append(path)
				elif f > cutoff_bound:
					continue
				if len(path) == self.n:
					goal_path = path + s[0]
					goal_cost = cost + self.E[self.__index__(path[-1])][self.__index__(s[0])]
					print(f"Path: {goal_path}, Cost: {goal_cost}")
					paths.append((goal_path, goal_cost))
					if best_bound == None or best_bound > cost + self.h[path[-1]]:
						best_bound = cost + self.h[path[-1]]
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
				print(f"\nMinimum Cost: {minimum[1]} and its Path: {minimum[0]}\n")
			if not stack:
				break






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
	G.a_star_search(s=("A", 0))
	G.dfbb_search(s=("A", 0))
	G.ida_star_search(s=("A", 0))