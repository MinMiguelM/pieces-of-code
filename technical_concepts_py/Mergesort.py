def mergesort(array):
    if len(array) <= 1:
        return
    
    mid = len(array) // 2
    L = array[:mid]
    R = array[mid:]

    mergesort(L)
    mergesort(R)

    left = right = index = 0
    while left < len(L) and right < len(R):
        if L[left] <= R[right]:
            array[index] = L[left]
            left += 1
        else:
            array[index] = R[right]
            right += 1
        index += 1
    
    while left < len(L):
        array[index] = L[left]
        left += 1
        index += 1

    while right < len(R):
        array[index] = R[right]
        right += 1
        index += 1


test = [5,7,2,8,9,10,1,85,0,12]
mergesort(test)
print(test)