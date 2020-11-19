import numpy as np
numbers=[]
for i in range(10):
    n=np.random.randint(1,100)
    numbers.append(n)
print("Unsorted array: ",numbers)

l=len(numbers)
it=1
for i in range(l):
	swapped=0
	for j in range(0,l-i-1):
		if numbers[j]>numbers[j+1]:
			swapped=1
			numbers[j+1],numbers[j]=numbers[j],numbers[j+1]
	if swapped==0:
		break
	print(f"iteration {it}: ",numbers)
	it+=1
