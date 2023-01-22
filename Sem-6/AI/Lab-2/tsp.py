#TRAVELING SALESMAN PROBLEM
#ROLL: CS20B1016
#NAME: V NAGASAI

from itertools import permutations

class Graph:
	def __init__(self, n):
		self.adjMatrix = []
		for i in range(n):
			self.adjMatrix.append([-1 for i in range(n)])
		self.n = n

	def add_edge(self, v1, v2):
		if v1 == v2:
			self.adjMatrix[v1][v2] = 0
			self.adjMatrix[v2][v1] = 0
		elif self.adjMatrix[v1][v2] == -1:
			dist = int(input(f"Enter the distance between {v1+1} - {v2+1} : "))
			self.adjMatrix[v1][v2] = dist
			self.adjMatrix[v2][v1] = dist
	
	def print_adj_matrix(self):
		for row in self.adjMatrix:
			for val in row:
				print(val, end=" ")
			print("")
	
	def travel_cost(self, arr):
		cost = 0
		n = len(arr)
		for i in range(n-1):
			cost += self.adjMatrix[arr[i]-1][arr[i + 1]-1]
		return cost
	
	def nearest_node(self, node, visited):
		min_cost = 9999
		for i, value in enumerate(self.adjMatrix[node]):
			if value != 0 and (i + 1) not in visited and value < min_cost:
				index = i
				min_cost = value
		return (index, min_cost)

n = int(input("Enter the number of nodes: "))
nodes = [i+1 for i in range(n)]
G = Graph(n)
for i in range(n):
	for j in range(n):
		G.add_edge(i, j)
print("\n-------------Nodes-------------")
print(nodes)
print("-----------------------------------\n")
print("\n-------------Adjacency Matrix of Distances-------------")
G.print_adj_matrix()
print("-------------------------------------------------------\n")

G.nearest_node(0, [])

#BRUTE FORCE APPROACH
print("\n-------------Using Brute Force Approach-------------")
def brute_force(arr, start = int(input("Enter the start node: ")),left = 0, right = n, min_cost = 9999, min_traversal=[]):
	if left == right and start == arr[0]:
		temp = arr.copy()
		temp.append(start)
		cost = G.travel_cost(temp)
		print(f"Cost: {cost}, Traversal: {temp}")
		if cost < min_cost:
			min_cost = cost
			min_traversal = temp
	else:
		for i in range(left, right):
			arr[left], arr[i] = arr[i], arr[left]
			min_cost, min_traversal = brute_force(arr, start, left+1, right,min_cost, min_traversal)
			arr[left], arr[i] = arr[i], arr[left]
	return (min_cost, min_traversal)

min_cost, min_traversal = brute_force(nodes)
print("\nMinimum cost: ", min_cost, ", Minimum traversal: ",min_traversal, "\n")

#GREEDY APPROACH
print("\n-------------Using Greedy Approach-------------")
def greedy(nodes, start = int(input("Enter the start node: "))):
	min_traversal = []
	min_traversal.append(start)
	node = start - 1
	min_cost = 0
	for i in range(len(nodes)-1):
		node, cost = G.nearest_node(node, min_traversal)
		min_traversal.append(node+1)
		min_cost += cost
	min_cost += G.adjMatrix[start-1][node]
	min_traversal.append(start)
	return (min_cost, min_traversal)

min_cost, min_traversal = greedy(nodes)
print("\nMinimum cost: ", min_cost, ", Minimum traversal: ",min_traversal, "\n")

#DYNAMIC PROGRAMMING
print("\n-------------Using Dynamic Programming Approach-------------")
def dynamic_programming(start = int(input("Enter the start node: "))):
	arr = []
	for i in range(G.n):
		if i != start - 1:
			arr.append(i)
	
	min_cost = 9999
	min_traversal = []
	next_permutation = permutations(arr)
	for permutation in next_permutation:
		current_cost = 0
		node = start - 1
		current_traversal = []
		current_traversal.append(node+1)
		for i in permutation:
			current_cost += G.adjMatrix[node][i]
			node = i
			current_traversal.append(node+1)
		current_cost += G.adjMatrix[node][start-1]
		current_traversal.append(start)
		print(f"Cost: {current_cost}, Traversal: {current_traversal}")
		if current_cost < min_cost:
			min_cost = current_cost
			min_traversal = current_traversal
	return (min_cost, min_traversal)


min_cost, min_traversal = dynamic_programming()
print("\nMinimum cost: ", min_cost, ", Minimum traversal: ",min_traversal, "\n")