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
s = input("Enter the parentheses string: ")

start = 0
end = 0
opens = 0
closes = 0
for index, value in enumerate(s):
	if value == '(':
		stack.push('(')
		opens += 1
		if opens == 0:
			opens = index
	else:
		if stack.top is not None:
			stack.pop()
		else:
			opens = 0
		closes += 1
if stack.top is None and opens == closes:
	print("Valid")
else:
	print("Invalid")
