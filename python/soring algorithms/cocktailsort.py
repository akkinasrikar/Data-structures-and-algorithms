import numpy as np
numbers=[]
for i in range(10):
    n=np.random.randint(1,100)
    numbers.append(n)
print("Unsorted array: ",numbers)

l=len(numbers)
it=1

def cocktailsort(array,n):
	start=0
	end=n
	while start!=end:
		check=1
		for i in range(start,end-1):
			if array[i]>array[i+1]:
				array[i],array[i+1]=array[i+1],array[i]	
				check=0
		end=end-1
		print(array)
		if check==1:
			break
		check=1
		for i in range(end,start,-1):
			if array[i]<array[i-1]:
				array[i],array[i-1]=array[i-1],array[i]
				check=0
		start=start+1
		print(array)
		if check==1:
			break

cocktailsort(numbers,l)
print("sorted array: ",numbers)
