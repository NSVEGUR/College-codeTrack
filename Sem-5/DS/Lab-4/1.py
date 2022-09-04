#Name: V Nagasaivegur
#Roll: CS20B1016

import pickle
import random

FILE_NAME = 'library'

class Book():
	def __init__(self, id):
		self.ISSN = random.randint(1, 10000)
		self.title = input(f'Enter the title of book - {id}: ')
		self.price = int(input(f'Enter the price of {self.title}: '))
		self.edition = int(input("Enter the edition: "))
		self.year = int(input("Enter the year: "))
		self.authorName = input("Enter the author name: ")

choice = 1
while(choice!=4):
	print("1. Write")
	print("2. Read")
	print("3. Search")
	print("4. Exit")
	choice = int(input("Enter your choice: "))
	if(choice == 1):
		n = int(input("Enter the number of Books you wanna add to library: "))
		Library = {}
		try:
			file = open(FILE_NAME, 'rb')
			Library = pickle.load(file)
			file.close()
		except:
			print("File is not there so created named library.")
		file = open(FILE_NAME, 'wb')
		for i in range(n):
			book = Book(i+1)
			Library[book.title] = book
		pickle.dump(Library, file)
		file.close()
	elif(choice == 2):
		try:
			file = open(FILE_NAME, 'rb')
			Library = pickle.load(file)
			print("Books in the library are: \n")
			i = 1
			for key, value in Library.items():
				print(f'{i}.\tTitle: {key}')
				print(f'\tISSN: {value.ISSN}')
				print(f'\tPrice: {value.price}')
				print(f'\tEdition: {value.edition}')
				print(f'\tYear: {value.year}')
				print(f'\tAuthorName: {value.authorName}')
				print("\n")
				i+=1
			file.close()
		except:
			print("There is nothing in the file to read.")
			continue
	elif(choice == 3):
		try:
			file = open(FILE_NAME, 'rb')
			Library = pickle.load(file)
			title = input("Enter the book title you wanna search: ")
			book = Library[title]
			print("Book is found.")
			print("\n")
			print(f'\tTitle: {book.title}')
			print(f'\tISSN: {book.ISSN}')
			print(f'\tPrice: {book.price}')
			print(f'\tEdition: {book.edition}')
			print(f'\tYear: {book.year}')
			print(f'\tAuthorName: {book.authorName}')
			print("\n")
			file.close()
		except KeyError:
			print("Book is not found in the library")
		except:
			print("There is no such file to search.")
	elif(choice == 4):
		print("Program is exited")
		exit(0)
	else:
		print("Please Enter a valid choice")