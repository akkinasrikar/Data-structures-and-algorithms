import numpy as np
numbers=[]
for i in range(10):
    n=np.random.randint(1,100)
    numbers.append(n)
print("Unsorted array: ",numbers)

l=len(numbers)
for i in range(l):
	index=i
	for j in range(i+1,l):
		if numbers[index]>numbers[j]:
			index=j
	numbers[i],numbers[index]=numbers[index],numbers[i]
	print(f"iteration {i+1} :",numbers)