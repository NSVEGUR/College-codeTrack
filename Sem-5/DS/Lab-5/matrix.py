# Name: V Nagasai
# Roll: CS20B1016
# Q: Write a python program to perform matrix operations and solve a system of linear equations.
# 1. Matrix Addition
# 2. Matrix Subtraction
# 3. Scalar Matrix Multiplication
# 4. Elementwise Matrix Multiplication
# 5. Matrix Multiplication
# 6. Matrix Transpose
# 7. Trace of a Matrix
# 8. Solve System of Linear Equations
# 9. Determinant
# 10. Inverse
# 11. Singular Value Decomposition
# 12. Eigen Value
# 13. Search an Element
# 14. Sum of Difference of Upper and Lower Triangular Matrix
# 15. Exit

import numpy as np

choice = 1

while(choice!=9):
	print("\n---------------------------------------------------------")
	print("1. Matrix Addition")
	print("2. Matrix Subtraction")
	print("3. Scalar Matrix Multiplication")
	print("4. Elementwise Matrix Multiplication")
	print("5. Matrix Multiplication")
	print("6. Matrix Transpose")
	print("7. Trace of a Matrix")
	print("8. Solve System of Linear Equations")
	print("9. Determinant")
	print("10. Inverse")
	print("11. Singular Value Decomposition")
	print("12. Eigen Value")
	print("13. Search an Element")
	print("14. Sum of Difference of Upper and Lower Triangular Matrix")
	print("15. Exit")
	print("---------------------------------------------------------")
	choice = int(input("Enter your choice: "))
	if(choice==1):
		print("\n---Matrix Addition---\n")
		print("\n---use n1 & n2, m1 & m2 same---\n")
		m1 = int(input("Enter M of matrix - 1: "))
		n1 = int(input("Enter N of matrix - 1: "))
		m2 = int(input("Enter M of matrix - 2: "))
		n2 = int(input("Enter N of matrix - 2: "))
		print("---Matrix 1 input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n1)]for r in range(m1)])
		print("---Matrix 2 input---")
		B = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n2)]for r in range(m2)])
		try:
			C = np.add(A, B)
			print("\nA: ")
			print(A)
			print("\nB: ")
			print(B)
			print("Addition of A and B is: \n")
			print(C, "\n")
		except:
			print("Exception in addition please use n1 & n2, m1 & m2 same")
	elif(choice==2):
		print("\n---Matrix Subtraction---\n")
		print("\n---use n1 & n2, m1 & m2 same---\n")
		m1 = int(input("Enter M of matrix - 1: "))
		n1 = int(input("Enter N of matrix - 1: "))
		m2 = int(input("Enter M of matrix - 2: "))
		n2 = int(input("Enter N of matrix - 2: "))
		print("---Matrix 1 input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n1)]for r in range(m1)])
		print("---Matrix 2 input---")
		B = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n2)]for r in range(m2)])
		try:
			C = np.subtract(A, B)
			print("\nA: ")
			print(A)
			print("\nB: ")
			print(B)
			print("Subtraction of A and B is: \n")
			print(C, "\n")
		except:
			print("Exception in subtraction please use n1 & n2, m1 & m2 same")
	elif(choice==3):
		print("\n---Scalar Matrix Multiplication---\n")
		m = int(input("Enter M of matrix: "))
		n = int(input("Enter N of matrix: "))
		k = int(input("Enter K for scalar multiplication: "))
		print("---Matrix  input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n)]for r in range(m)])
		B = k*A
		print("\nA: ")
		print(A)
		print("Scalar Matrix Multiplication of A and k is: \n")
		print(B, "\n")
	elif(choice==4):
		print("\n---Element-wise Matrix Multiplication---\n")
		print("\n---use n1 & n2, m1 & m2 same---\n")
		m1 = int(input("Enter M of matrix - 1: "))
		n1 = int(input("Enter N of matrix - 1: "))
		m2 = int(input("Enter M of matrix - 2: "))
		n2 = int(input("Enter N of matrix - 2: "))
		print("---Matrix 1 input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n1)]for r in range(m1)])
		print("---Matrix 2 input---")
		B = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n2)]for r in range(m2)])
		try:
			C = np.multiply(A, B)
			print("\nA: ")
			print(A)
			print("\nB: ")
			print(B)
			print("Element-wise of A and B is: \n")
			print(C, "\n")
		except:
			print("Exception in element wise multiplication please use n1 & n2, m1 & m2 same")
	elif(choice==5):
		print("\n---Matrix Multiplication---\n")
		print("\n---use n1 & m2 same---\n")
		m1 = int(input("Enter M of matrix - 1: "))
		n1 = int(input("Enter N of matrix - 1: "))
		m2 = int(input("Enter M of matrix - 2: "))
		n2 = int(input("Enter N of matrix - 2: "))
		print("---Matrix 1 input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n1)]for r in range(m1)])
		print("---Matrix 2 input---")
		B = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n2)]for r in range(m2)])
		try:
			C = np.matmul(A, B)
			print("\nA: ")
			print(A)
			print("\nB: ")
			print(B)
			print("Matrix multiplication of A and B is: \n")
			print(C, "\n")
		except:
			print("Exception in multiplication please use n1 & m2 same")
	elif(choice==6):
		print("\n---Matrix Transpose---\n")
		m = int(input("Enter M of matrix: "))
		n = int(input("Enter N of matrix: "))
		print("---Matrix  input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n)]for r in range(m)])
		print("\nA: ")
		print(A)
		print("Transpose of A is: \n")
		print(A.transpose(), "\n")
	elif(choice==7):
		print("\n---Trace of a Matrix---\n")
		m = int(input("Enter M of matrix: "))
		n = int(input("Enter N of matrix: "))
		print("---Matrix  input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n)]for r in range(m)])
		print("\nA: ")
		print(A)
		print("Trace of A is: \n")
		print(A.trace(), "\n")
	elif(choice==8):
		print("\n---Solving System of linear equations---\n")
		m1 = int(input("Enter M of matrix - 1: "))
		n1 = int(input("Enter N of matrix - 1: "))
		m2 = int(input("Enter M of matrix - 2: "))
		n2 = int(input("Enter N of matrix - 2: "))
		print("---Matrix 1 input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n1)]for r in range(m1)])
		print("---Matrix 2 input---")
		B = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n2)]for r in range(m2)])
		try:
			C = np.linalg.solve(A, B)
			print("\nA: ")
			print(A)
			print("\nB: ")
			print(B)
			print("Solution of linear equations A and B is: \n")
			print(C, "\n")
		except:
			print("Exception in solving system of linear equations")
	elif(choice==9):
		print("---Determinant of a Matrix---")
		m = int(input("Enter M of matrix: "))
		n = int(input("Enter N of matrix: "))
		print("---Matrix  input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n)]for r in range(m)])
		try:
			B = np.linalg.det(A)
			print("\nA: ")
			print(A)
			print("Determinant of A is: \n")
			print(B, "\n")
		except:
			print("Exception in finding determinant")
	elif(choice==10):
		print("---Inverse of a Matrix---")
		m = int(input("Enter M of matrix: "))
		n = int(input("Enter N of matrix: "))
		print("---Matrix  input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n)]for r in range(m)])
		try:
			B = np.linalg.inv(A)
			print("\nA: ")
			print(A)
			print("Inverse of A is: \n")
			print(B, "\n")
		except:
			print("Exception in finding inverse")
	elif(choice==11):
		print("---Singular value decomposition of a Matrix---")
		m = int(input("Enter M of matrix: "))
		n = int(input("Enter N of matrix: "))
		print("---Matrix  input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n)]for r in range(m)])
		u, s, vh = np.linalg.svd(A, full_matrices=False)
		print("\nA: ")
		print(A)
		print("Singular value decomposition of A is: \n")
		print(u, s, vh, "\n")
	elif(choice==12):
		print("---Eigen Values of a Matrix---")
		m = int(input("Enter M of matrix: "))
		n = int(input("Enter N of matrix: "))
		print("---Matrix  input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n)]for r in range(m)])
		w = np.linalg.eig(A)
		print("\nA: ")
		print(A)
		print("Eigen values of A is: \n")
		print(w, "\n")
	elif(choice==13):
		print("---Searching a Matrix---")
		m = int(input("Enter M of matrix: "))
		n = int(input("Enter N of matrix: "))
		print("---Matrix  input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n)]for r in range(m)])
		k = int(input("Enter the element to search: "))
		try:
			i = np.where(A == k)
			print("\nA: ")
			print(A)
			print("Position of k in matrix A is: \n")
			print(i, "\n")
		except:
			print("Exception in searching the element")
	elif(choice==14):
		print("\n---Difference of Sum of Upper and Lower Triangular Matrix---\n")
		m = int(input("Enter M of matrix: "))
		n = int(input("Enter N of matrix: "))
		print("---Matrix  input---")
		A = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(n)]for r in range(m)])
		sumUpper = 0
		sumLower = 0
		for r in range(m):
			for c in range(n):
				if(r <= c):
					sumUpper += A[r][c]
				if(c <= r):
					sumLower += A[r][c]
		print("\nA: ")
		print(A)
		print("Difference of Sum of Upper and Lower Triangular Matrix is: ", abs(sumUpper-sumLower), "\n")
	elif(choice == 15):
		print("\n---Program is exited---\n")
		exit(0)
	else:
		print("\nPlease Enter a valid choice.\n")