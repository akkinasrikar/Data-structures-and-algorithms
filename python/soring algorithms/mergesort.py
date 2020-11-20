import numpy as np
numbers=[]
for i in range(10):
    n=np.random.randint(1,100)
    numbers.append(n)
print("Unsorted array: ",numbers)
l=len(numbers)

def mergesort(array):

  	if len(array)>1:
  		m=len(array)//2
  		L=array[:m]
  		R=array[m:]
  		mergesort(L)
  		mergesort(R)

  		i=j=k=0;

  		while i<len(L) and j<len(R):
  			if L[i]<R[j]:
  				array[k]=L[i]
  				i+=1
  			else:
  				array[k]=R[j]
  				j+=1
  			k=k+1

  		while i<len(L):
  			array[k]=L[i]
  			i+=1
  			k+=1
  		while j<len(R):
  			array[k]=R[j]
  			j+=1
  			k+=1


		
mergesort(numbers)
print("sorted array: ",numbers)


