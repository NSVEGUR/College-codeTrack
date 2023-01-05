def DFS(G, V, node):
	if node not in V:
		print(node, end=" ")
		V.append(node)
		for neighbor in G[node]:
			DFS(G, V, neighbor)
	return V

def DFS_Disconnected(G, V):
	for node in G:
		if node not in V:
			V = DFS(G, V, node)

G = {
	"P": ["Q", "R", "S"],
	"Q": ["P", "R"],
	"R": ["P", "T"],
	"S": ["P"],
	"T": []
}

print("connected Graph DFS from P: ")
V = list()
DFS(G, V, "P")
print("\n")
print("Connected Graph DFS from T: ")
V = list()
DFS(G, V, "T")
print("\n")
print("Disconnected Graph DFS: ")
V = list()
DFS_Disconnected(G, V)
print("\n")