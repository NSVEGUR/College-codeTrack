class Node:
	def __init__(self, data = 0, next = None):
		self.data = data
		self.next = next

class Queue:
	def __init__(self):
		self.head = None
		self.tail = None
	
	def enqueue(self, data):
		if self.tail is None:
			self.tail = Node(data)
			self.head = self.tail
		else:
			temp = Node(data)
			self.tail.next = temp
			self.tail = temp
		print(data, " enqueued successfully to the queue.")
	
	def dequeue(self):
		if self.head is None:
			return -1
		else:
			temp = self.head
			self.head = self.head.next
			if self.head is None:
				self.tail = None
			return temp.data
	
	def peek(self):
		if self.head is None:
			return -1
		else:
			return self.head.data

	def print(self):
		temp = self.head
		if temp is None:
			print("Queue is Empty.")
		else:
			print("Queue is: ")
			while(temp is not None):
					print(temp.data, end=" ")
					temp = temp.next
			print("\n")
			# print(temp.data)

queue = Queue()
choice = 1
while choice != 5:
	print("1. Enqueue")
	print("2. Dequeue")
	print("3. Peek (Prints the front element of the queue)")
	print("4. Print (Prints the entire queue)")
	print("5. Exit")
	choice = int(input("Please Enter your choice: "))
	if(choice == 1):
		data = int(input("Please Enter the data to push: "))
		queue.enqueue(data)
	elif(choice == 2):
		data = queue.dequeue()
		if(data == -1):
			print("Queue is Empty.")
		else:
			print(data, " is dequeued from the queue successfully.")
	elif(choice == 3):
		data = queue.peek()
		if(data == -1):
			print("Queue is Empty.")
		else:
			print(data, " is the front element of the queue.")
	elif(choice == 4):
		queue.print()
	elif(choice == 5):
		print("Program is Exited.")
		exit(0)
	else:
		print("Please enter a valid choice.")
