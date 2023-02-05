#Name: V Nagasai
#Roll: CS20B1016
#Traveling salesman problem using BFS, DFS and IDS


class Graph:
	#Initialization of graph using vertices and edges
	def __init__(self, V: list, E:list):
		self.V = V
		self.n = len(V)
		self.E = [[0 for _ in range(self.n)] for _ in range(self.n)]
		for edge in E:
			(X, Y, cost) = edge
			if X != Y:
				x, y = self.V.index(X), self.V.index(Y)
				self.E[x][y] = cost
				self.E[y][x] = cost

	#Utility function which returns index of given vertex
	def index(self, vertex):
		return self.V.index(vertex)

	#Finding all the paths using breadth first search by implementing queue and taking the minimum as optimal cost(as of now) for traveling
	def BFS(self, start_state):
		print("----------TSP using BFS----------")
		start_node = self.index(start_state[0])
		queue = []
		queue.append(start_state)
		paths = []
		while queue:
			path, cost = queue.pop(0)
			print(f"State: ({path}, {cost})")
			path_len = len(path)
			current_node = self.index(path[-1])
			if path_len == self.n:
				final_path = path + start_state[0]
				final_cost = cost + self.E[current_node][start_node]
				print(f"Goal State: ({final_path}, {final_cost})")
				paths.append((final_path, final_cost))
			for neighbor_index, neighbor_cost in enumerate(self.E[current_node]):
				neighbor = self.V[neighbor_index]
				if neighbor not in path and neighbor_cost:
					new_path = path + neighbor
					new_cost = cost + neighbor_cost
					queue.append((new_path, new_cost))
		min_path = min(paths, key= lambda x: x[1])
		print("\nMinimum cost path: ", min_path, "\n")

	#Finding all the paths using depth first search by implementing stack and taking the minimum as optimal cost(as of now) for traveling
	def DFS(self, start_state):
		print("----------TSP using DFS----------")
		start_node = self.index(start_state[0])
		stack = []
		stack.append(start_state)
		paths = []
		while stack:
			path, cost = stack.pop()
			print(f"State: ({path}, {cost})")
			path_len = len(path)
			current_node = self.index(path[-1])
			if path_len == self.n:
				final_path = path + start_state[0]
				final_cost = cost + self.E[current_node][start_node]
				print(f"Goal State: ({final_path}, {final_cost})")
				paths.append((final_path, final_cost))
			for neighbor_index, neighbor_cost in enumerate(self.E[current_node]):
				neighbor = self.V[neighbor_index]
				if neighbor not in path and neighbor_cost:
					new_path = path + neighbor
					new_cost = cost + neighbor_cost
					stack.append((new_path, new_cost))
		min_path = min(paths, key= lambda x: x[1])
		print("\nMinimum cost path: ", min_path, "\n")

	#Utility function for Iterative deepening search which does breadth first search upto a certain depth
	def DLS(self, start_state, max_depth):
		queue = []
		queue.append(start_state)
		paths = []
		print(f"\n----------Max Depth = {max_depth}----------\n")
		while queue:
			path, cost = queue.pop(0)
			path_len = len(path)
			if path_len <= max_depth:
				print(f"State: ({path}, {cost})")
				current_node = self.index(path[-1])
				if path_len == self.n:
					final_path = path + start_state[0]
					start_node = self.index(start_state[0])
					final_cost = cost + self.E[current_node][start_node]
					print(f"Goal State: ({final_path}, {final_cost})")
					paths.append((final_path, final_cost))
				for neighbor_index, neighbor_cost in enumerate(self.E[current_node]):
					neighbor = self.V[neighbor_index]
					if neighbor not in path and neighbor_cost:
						new_path = path + neighbor
						new_cost = cost + neighbor_cost
						queue.append((new_path, new_cost))
		return paths

	#Iterative deepening algorithm which does depth first search to decrease space complexity based on levels
	def IDS(self, start_state, max_depth):
		print("----------TSP using IDS----------")
		for i in range(max_depth):
			paths = self.DLS(start_state, i+1)
		min_path = min(paths, key= lambda x: x[1])
		print("\nMinimum cost path: ", min_path, "\n")


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
	G.BFS(('B', 0))
	G.DFS(('B', 0))
	G.IDS(('B', 0), len(V))