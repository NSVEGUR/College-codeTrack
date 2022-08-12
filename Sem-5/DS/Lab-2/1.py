#Name: V Nagasai
#Roll: CS20B1016
# Write a python script to implement student details using a dictionary. The roll number of the student will be the key, the value will be a list containing the name, CGPA, and mobile number of the respective student. The program should be implemented as a menu-driven program with the following menus,
# 1. Insert
# 2. Delete
# 3. Search
# 4. Exit

dictionary = {}
choice = 1
print("-----DICTIONARY IMPLEMENTATION-----")
while(choice != 4):
	print("1. INSERT")
	print("2. DELETE")
	print("3. SEARCH")
	print("4. EXIT")
	choice = int(input("Enter your choice: "))
	if(choice == 1):
		rollNumber = input("Enter the Roll Number of the Student: ")
		name = input(f'Enter the name of student {rollNumber}: ')
		cgpa = input(f'Enter the cgpa of student {rollNumber}: ')
		mobileNumber = input(f'Enter the mobile number of student {rollNumber}: ')
		dictionary[rollNumber] = [name, cgpa, mobileNumber]
		print(f'{rollNumber} is inserted.')
	elif(choice == 2):
		rollNumber = input("Enter the Roll Number of the Student You Wanna Delete: ")
		result = dictionary.pop(rollNumber, -1)
		if(result == -1):
			print(f'{rollNumber} is NOT FOUND')
		else:
			print(f'{rollNumber} is deleted.')
	elif(choice == 3):
		rollNumber = input("Enter the Roll Number of the Student You Wanna Search: ")
		if rollNumber in dictionary:
			print(f'{rollNumber} : {dictionary[rollNumber]}')
		else:
			print(f'{rollNumber} is NOT FOUND')
	elif(choice == 4):
		print("Program is Exited")
	else:
		print("Please enter a valid choice")

