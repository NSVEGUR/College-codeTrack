def BFS(G, V, node):
	Q = list()
	V.append(node)
	Q.append(node)
	print(node, end=" ")
	while Q:
		N = Q.pop()
		for neighbor in G[N]:
			if neighbor not in V:
				V.append(neighbor)
				Q.append(neighbor)
				print(neighbor, end=" ")
	return V

def BFS_Disconnected(G, V):
	for node in G:
		if node not in V:
			V = BFS(G, V, node)

G = {
	"P": ["Q", "R", "S"],
	"Q": ["P", "R"],
	"R": ["P", "T"],
	"S": ["P"],
	"T": []
}

print("Connected Graph BFS from P: ")
V = list()
BFS(G, V, "P")
print("\n")
print("Connected Graph BFS from T: ")
V = list()
BFS(G, V, "T")
print("\n")
print("Disconnected Graph BFS: ")
V = list()
BFS_Disconnected(G, V)
print("\n")
