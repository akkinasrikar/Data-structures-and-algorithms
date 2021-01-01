import numpy as np
numbers=[]
for i in range(10):
    n=np.random.randint(1,100)
    numbers.append(n)
print("Unsorted array: ",numbers)

l=len(numbers)
it=1

def insertionsortRecursive(array,n):
	if n<=1:
		return
	insertionsortRecursive(array,n-1)
	last_element=array[n-1]
	j=n-2	
	while j>=0 and array[j]>last_element:
		array[j+1]=array[j]
		j=j-1
	array[j+1]=last_element
	print(array[:n])

insertionsortRecursive(numbers,l)
print("sorted array: ",numbers)