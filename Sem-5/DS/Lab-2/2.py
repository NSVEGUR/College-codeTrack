#Name: V Nagasai
#Roll: CS20B1016
#Write a python program to implement set operations using menu-driven programming. The menus to be implemented are as follows,
# 1. Create Empty Set
# 2. Insert
# 3. Delete
# 4. Search
# 5. Print
# 6. Union
# 7. Intersection
# 8. Set Difference
# 9. Symmetric Difference
# 10. Exit

choice = 1
created = False
s = {}
print("-----SET IMPLEMENTATION-----")
while(choice != 10):
	print("1. Create Empty Set")
	print("2. Insert")
	print("3. Delete")
	print("4. Search")
	print("5. Print")
	print("6. Union")
	print("7. Intersection")
	print("8. Set Difference")
	print("9. Symmetric Difference")
	print("10. Exit")
	choice = int(input("Enter your choice: "))
	if(choice == 1):
		s = set()
		print("Empty set is created")
		created = True
	elif(choice == 2):
		if(not created):
			print("Please create a empty set first")
		else:
			el = input("Enter the element to insert: ")
			s.add(el)
			print(f'{el} is inserted.')
	elif(choice == 3):
		if(not created):
			print("Please create a empty set first")
		else:
			el = input("Enter the element to delete: ")
			s.discard(el)
			print(f'{el} is deleted.')
	elif(choice == 4):
		if(not created):
			print("Please create a empty set first")
		else:
			el = input("Enter the element to search: ")
			if el in s:
				print(f'{el} is found.')
			else:
				print(f'{el} is not found.')
	elif(choice == 5):
		if(not created):
			print("Please create a empty set first")
		else:
			print(s)
	elif(choice == 6):
		m = int(input("Enter the number of elements in set A: "))
		A = set()
		for i in range(m):
			A.add(input(f'Enter the element {i+1}: '))
		n = int(input("Enter the number of elements in set B: "))
		B = set()
		for i in range(n):
			B.add(input(f'Enter the element {i+1}: '))
		C = A.union(B)
		print(f'Union of sets A and B {C}')
	elif(choice == 7):
		m = int(input("Enter the number of elements in set A: "))
		A = set()
		for i in range(m):
			A.add(input(f'Enter the element {i+1}: '))
		n = int(input("Enter the number of elements in set B: "))
		B = set()
		for i in range(n):
			B.add(input(f'Enter the element {i+1}: '))
		C = A.intersection(B)
		print(f'Intersection of sets A and B {C}')
	elif(choice == 8):
		m = int(input("Enter the number of elements in set A: "))
		A = set()
		for i in range(m):
			A.add(input(f'Enter the element {i+1}: '))
		n = int(input("Enter the number of elements in set B: "))
		B = set()
		for i in range(n):
			B.add(input(f'Enter the element {i+1}: '))
		C = A.difference(B)
		print(f'Difference of sets A and B {C}')
	elif(choice == 9):
		m = int(input("Enter the number of elements in set A: "))
		A = set()
		for i in range(m):
			A.add(input(f'Enter the element {i+1}: '))
		n = int(input("Enter the number of elements in set B: "))
		B = set()
		for i in range(n):
			B.add(input(f'Enter the element {i+1}: '))
		C = A.symmetric_difference(B)
		print(f'Symmetric Difference of sets A and B {C}')
	elif(choice == 10):
		print("Program is Exited.")
	else:
		print("Please Enter a Valid Choice.")




