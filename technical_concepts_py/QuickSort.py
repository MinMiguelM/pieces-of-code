"""Implement quick sort in Python.
Input a list.
Output a sorted list."""

def partition(array, left, right, pivot):
	while left <= right:
		while array[left] < pivot:
			left += 1
		while array[right] > pivot:
			right -= 1
		if left <= right:
			tmp = array[left]
			array[left] = array[right]
			array[right] = tmp
			left += 1
			right -= 1
	return left 

def quicksortHelper(array, left, right):
	if left >= right:
		return

	pivot = array[(left + right) // 2]
	index = partition(array, left, right, pivot)
	quicksortHelper(array, left, index - 1)
	quicksortHelper(array, index, right)

def quicksort(array):
	if len(array) <= 1:
		return
	quicksortHelper(array, 0, len(array) - 1)
	
	

test = [5,7,2,8,9,10,1,85,0,12]
quicksort(test)
print(test)
