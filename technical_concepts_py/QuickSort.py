"""Implement quick sort in Python.
Input a list.
Output a sorted list."""

def partition(array,s,l):
	pivot = l
	start = s
	while start!=pivot:
		if array[start] > array[pivot]:
			aux = array[start]
			array[start] = array[pivot-1]
			array[pivot-1] = array[pivot]
			array[pivot] = aux
			pivot -= 1
		else:
			start += 1
	return pivot

def quicksort(array,s,l):
	if s < l:
		p = partition(array,s,l)
		quicksort(array,s,p-1)
		quicksort(array,p+1,l)
		return array
	return array
	

test = [5,7,2,8,9,10,1,85,0,12]
print quicksort(test,0,len(test)-1)
