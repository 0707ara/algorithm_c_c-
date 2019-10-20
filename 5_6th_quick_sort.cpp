#include <stdio.h>
	
	int number=10;
	int data[10] = {1,10,5,8,7,6,4,3,2,9};
	
	void quicksort(int *data, int start, int end){
		if(start>= end){ //when the element is only one
			return;
		}
		int key = start;	  //take the first element as pivot
		int i = start +1;     //left index
		int j=end;			  //right index
		int temp;
		
		while(i<=j){ //do it till the index are reversed
			while(data[i]<=data[key]){ //repeat till the data[i] meets greater than data[key]
			i++;
			}
			while(data[j]>=data[key] && j>start){ //repeat till the data[i] meets less than data[key]
			j--;	
			}
			if(i>j){
				temp=data[j];
				data[j]=data[key];
				data[key]=temp;
			}
			else{
				temp=data[j];
				data[j]=data[i];
				data[i]=temp;
			}	
		}
		//data[j] is sorted wherever it is located
		//there's two sector before j and after j
		//call the function agn for each section
		
		quicksort(data,start,j-1);
		quicksort(data,j+1,end);
	}

int main(void){
	int i;
	quicksort(data,0,number-1);
	for(i=0;i<10;i++)
	printf("%d ",data[i]);
		
	}
	

