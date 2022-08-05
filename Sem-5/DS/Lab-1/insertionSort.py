# Roll: CS20B1016
# Name: V Nagasai
# Write a python program to sort a list of ‘n’ elements using insertion sort. 
# Do not use sort() function. Maintain proper boundary conditions.

# List input
list1 = []
for i in range(int(input("Enter the size of the array: "))):
	list1.append(int(input(f'Enter the element - {i+1} : ')))

print("List Before Insertion Sort: ",list1)

# Insertion Sort
for i in range(1, len(list1)):
	# If previous element is lesser than the present then it is sorted till i so continue
	if(list1[i] > list1[i-1]):
		continue
	# If not the sort till you find the lesser element than the present
	for j in range(i, 0, -1):
		if(list1[j] < list1[j-1]):
			list1[j], list1[j-1] = list1[j-1], list1[j]

print("List After Insertion Sort: ",list1)
