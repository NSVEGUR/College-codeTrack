# Roll: CS20B1016
# Name: V Nagasai
# Write a program to search for a value ‘k’ in a list of ‘n’ elements using binary search. 
# sort() function can be used to sort the list. Maintain proper boundary conditions.


list1 = []
# List input
for i in range(int(input("Enter the size of the array: "))):
	list1.append(int(input(f'Enter the element - {i+1} : ')))

# Element to search
x = int(input("Enter the element you wanna search: "))

# Sorting
list1.sort()

print("After Sorting Given List: ", list1)

left = 0
right = len(list1)
#If the index is out of range return -1 [i.e., the element is not found]
index = -1
while(left < right):
	mid = left + (right - left) // 2
	# If the element is found return that index
	if(list1[mid] == x):
		index = mid
		break
	# If mid element is greater than the element then the element should be in the first half of the array
	elif(list1[mid]>x):
		right = mid - 1
	# If mid element is lesser than the element then the element should be in the second half of the array
	else:
		left = mid + 1

if(index!=-1):
	print(f'Index of the  element {x} is : ', index);
else:
	print("Element is not found")

