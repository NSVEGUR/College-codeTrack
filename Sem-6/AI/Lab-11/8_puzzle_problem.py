# 8 Puzzle Problem
#CS20B1016
#V Nagasai

from queue import PriorityQueue
from itertools import count
import copy

class Node:
    def __init__(self, data, level, f):
        self.parent = None
        self.data = data
        self.level = level
        self.f = f

    def find(self, x):
        for i in range(len(self.data)):
            for j in range(len(self.data)):
                if self.data[i][j] == x:
                    return [i,j]

    def shuffle(self,curr,next):
        if next[0] >= 0 and next[0] < len(self.data) and next[1] >= 0 and next[1] < len(self.data):
            nextNode = copy.deepcopy(self.data)
            temp = nextNode[next[0]][next[1]]
            nextNode[next[0]][next[1]] = nextNode[curr[0]][curr[1]]
            nextNode[curr[0]][curr[1]] = temp
            return nextNode
        else:
            return None

    def childGen(self):
        curr = self.find('-')
        neighbors = [[curr[0], curr[1]+1], [curr[0], curr[1]-1], [curr[0]+1, curr[1]], [curr[0]-1, curr[1]]]
        children = []
        for next in neighbors:
            child = self.shuffle(curr,next)
            if child is not None:
                childNode = Node(child, self.level+1, 0)
                childNode.parent = self
                children.append(childNode)
        return children

class Solution:
    def __init__(self, size, initial, final):
        self.size = size
        self.initial = initial
        self.final = final
        self.open = PriorityQueue()
        self.closed = []

    def find(self, x):
        for i in range(len(self.final)):
            for j in range(len(self.final)):
                if self.final[i][j] == x:
                    return [i,j]

    def h_1(self, curr: Node):
        counter = 0
        for i in range(self.size):
            for j in range(self.size):
                if self.final[i][j] != curr.data[i][j] and curr.data[i][j] != '-':
                    counter += 1
        return counter

    def h_2(self, curr: Node):
        counter = 0
        for i in range(self.size):
            for j in range(self.size):
                if self.final[i][j] != curr.data[i][j] and curr.data[i][j] != '-':
                    temp = self.find(curr.data[i][j])
                    counter += abs(i - temp[0]) + abs(j - temp[1])
        return counter

    def f_1(self, curr: Node):
        h_curr =  self.h_1(curr)
        g_curr = curr.level  
        f_curr = g_curr + h_curr
        return f_curr  

    def f_2(self, curr: Node):
        h_curr =  self.h_2(curr)
        g_curr = curr.level  
        f_curr = g_curr + h_curr
        return f_curr

    def heuristic_1(self):
        start = Node(self.initial,0,0)
        start.f = self.f_1(start)
        unique = count()
        self.open.put((start.f,unique, start))
        while True:
            curr = self.open.get()[2]
            if(self.h_1(curr) == 0): 
                path = []
                while curr.parent is not None:
                    path.append(curr.data)
                    curr = curr.parent
                path.append(curr.data)
                path.reverse()
                break
            for child in curr.childGen():
                child.f = self.f_1(child)
                if child not in self.closed: 
                    self.open.put((child.f,next(unique), child))
            self.closed.append(curr)
        print("The path from start to goal: ")
        for cur in path:
            print(" ")
            print("  ↓ ")
            print(" ")  
            for i in cur:
                for j in i:
                    print(j,end=" ")
                print("")

    def heuristic_2(self):
        start = Node(self.initial,0,0)
        start.f = self.f_2(start)
        unique = count()
        self.open.put((start.f,unique, start))
        while True:
            curr = self.open.get()[2]
            if(self.h_2(curr) == 0): 
                path = []
                while curr.parent is not None:
                    path.append(curr.data)
                    curr = curr.parent
                path.append(curr.data)
                path.reverse()
                break
            for child in curr.childGen():
                child.f = self.f_2(child)
                if child not in self.closed: 
                    self.open.put((child.f,next(unique), child))
            self.closed.append(curr)
         # the path from start to goal
        print("The path from start to goal: ")
        for cur in path:
            print(" ")
            print("  ↓ ")
            print(" ")
            for i in cur:
                for j in i:
                    print(j,end=" ")
                print("")

if __name__ == "__main__":
    initial_state = [
        [2, 8, 3],
        [1, 6, 4],
        [7, '-', 5]
		]
    final_state = [
        [1, 2, 3],
        [8, '-', 4],
        [7, 6, 5]
		]
    print("Initial state: ", initial_state)
    print("Final state: ", final_state)

    obj = Solution(3, initial_state, final_state)
    # Using Heuristic 1
    print("\nSolution Using Heuristic 1: \n")
    obj.heuristic_1()
    # Using Heuristic 2
    print("\nSolution Using Heuristic 2: \n")
    obj.heuristic_2()

# Input 3
# Initial State:
# 2 8 3
# 1 6 4
# 7 - 5

# Final State:
# 1 2 3
# 8 - 4
# 7 6 5