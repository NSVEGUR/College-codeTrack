class Node:
	def __init__(self, data = 0, next = None):
		self.data = data
		self.next = next

class Stack:
	def __init__(self):
		self.top = None
	
	def push(self, data):
		if self.top is None:
			self.top = Node(data)
		else:
			temp = Node(data, self.top)
			self.top = temp
		print(data, " pushed successfully into the stack.")
	
	def pop(self):
		if self.top is None:
			return -1
		else:
			temp = self.top
			self.top = self.top.next
			return temp.data
	
	def print(self):
		temp = self.top
		if temp is None:
			print("Stack is Empty.")
		else:
			print("Stack is: ")
			while(temp is not None):
					print(temp.data, end=" ")
					temp = temp.next
			print("\n")

	def peek(self):
		if self.top is None:
			return -1
		else:
			return self.top.data

stack = Stack()
choice = 1
while choice != 5:
	print("1. Push")
	print("2. Pop")
	print("3. Peek (Prints the top element of the stack)")
	print("4. Print (Prints the entire stack)")
	print("5. Exit")
	choice = int(input("Please Enter your choice: "))
	if(choice == 1):
		data = int(input("Please Enter the data to push: "))
		stack.push(data)
	elif(choice == 2):
		data = stack.pop()
		if(data == -1):
			print("Stack is Empty.")
		else:
			print(data, " is popped out from the stack successfully.")
	elif(choice == 3):
		data = stack.peek()
		if(data == -1):
			print("Stack is Empty.")
		else:
			print(data, " is the peek of the stack.")
	elif(choice == 4):
		stack.print()
	elif(choice == 5):
		print("Program is Exited.")
		exit(0)
	else:
		print("Please enter a valid choice.")
