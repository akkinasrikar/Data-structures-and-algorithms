import numpy as np
numbers=[]
for i in range(10):
    n=np.random.randint(1,100)
    numbers.append(n)
print("Unsorted array: ",numbers)

l=len(numbers)
it=1

for i in range(1,l):
	element=numbers[i]
	j=i-1
	while(j>=0 and element<numbers[j]):
		numbers[j+1]=numbers[j]
		j=j-1
	numbers[j+1]=element
	print(f"iteration {it}: ",numbers)
	it+=1
