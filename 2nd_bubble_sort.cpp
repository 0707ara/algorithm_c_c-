#include <stdio.h>

int main(void){
	int i,j,temp;
	int arr1[10] = {1,10,5,8,7,6,4,3,2,9};
	for(i=0;i<10;i++){
		for(j=0;j<9-i;j++){
			if(arr1[j]>arr1[j+1]){
				temp=arr1[j];
				arr1[j]=arr1[j+1];
				arr1[j+1]=temp;
			}
		}
	}
	for(i=0;i<10;i++)
	printf("%d ",arr1[i]);
}
