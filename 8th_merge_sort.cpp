#include <stdio.h>

int number = 8;
int sorted[8]; //sorted array have to be declared by global variable
			   //global variable use the memory efficiently 
			   //if u declare the array as local variable its not efficient in the point of view of memory management
	void merge(int a[], int m, int middle, int n){
		int i =m;
		int j =middle +1;
		int k =m;
		//put elements in the array by ascending order
		while(i<=middle && j<=n){
			if(a[i]<a[j]){
				sorted[k]=a[i];
				i++;				
			}else{
				sorted[k]=a[j];
				j++;
			}
			k++;
		}
		//put the rest of the data till the end
		if(i>middle){
			for(int t=j;t<=n;t++){
				sorted[k]=a[t];
				k++;
			}
		}else{
			for(int t=i;t<=middle;t++){
				sorted[k]=a[t];
				k++;
			}
			
		}
		//copy the sorted array to the original orray
		for(int t=m;t<=n;t++){
			a[t] =sorted[t];
		}
	}
	void mergeSort(int a[],int m, int n){
		//compare when the size of the array is bigger than 1
		if(m<n){
			int middle = (m+n)/2;
			mergeSort(a,m,middle);
			mergeSort(a,middle+1,n);
			merge(a,m,middle,n);
		}
	}
int main(void){
	int array[number]={7,6,5,8,3,5,9,1};
	mergeSort(array,0,number-1);
	for(int i=0;i<number-1;i++){
			printf("%d ",array[i]);
	}

	
	}
