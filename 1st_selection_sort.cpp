#include <stdio.h>

int main(void)
{
	int i, j, min, index, temp;
	int arr1[10] = {1,10,5,8,7,6,4,3,2,9};
	
	for(i=0; i<10;i++){
		min=9999; //radomely generated number it should be the biggest among all
		for(j=i;j<10;j++){
			if(min>arr1[j]){
				min=arr1[j];
				index=j;
			}
		}
		temp=arr1[i];
		arr1[i]=arr1[index];
		arr1[index] = temp;
		//swapping
	}
	for(i=0;i<10;i++){
		printf("%d ", arr1[i]);
	}
	return 0;
}
