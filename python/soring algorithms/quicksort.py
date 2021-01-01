import numpy as np
numbers=[]
for i in range(5):
    n=np.random.randint(1,100)
    numbers.append(n)
print("Unsorted array: ",numbers)
l=len(numbers)

def partition(array,low,high):
	i=low-1
	pivot=array[high]
	print(f"i={i},pivot={pivot}")
	print(f"low={low},high={high}")
	for j in range(low,high):
		print(array)
		if array[j]<pivot:
			i=i+1
			array[i],array[j]=array[j],array[i]
			print(array)
	print("update pivot element position")
	array[i+1],array[high]=array[high],array[i+1]
	print(array)
	return i+1

def quicksort(array,low,high):
	if low<high:
		pi=partition(array,low,high)
		quicksort(array,low,pi-1)
		quicksort(array,pi+1,high)

quicksort(numbers,0,l-1)

print("sorted array: ",numbers)