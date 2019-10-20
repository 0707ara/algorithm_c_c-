#include <stdio.h>

int main(void){
	int temp;
	int count[5];
	int array[30] = {
		1,3,2,4,1,3,3,1,5,5,
		1,3,2,4,1,3,3,1,5,5,
		1,3,2,4,1,3,3,1,5,5
	};
	for(int i=0;i<5;i++){
	count[i] = 0 ;
	}	
	for(int i=0;i<30;i++){
		count[array[i]-1]++;
	}
	for(int i=0;i<5;i++){
		if(count[i !=0]){		
			for(int j=0;j<count[i];j++){
			printf("%d ",i + 1);
			}
		}
	}//depending on the size of the data, it can be used if the data is limited ok to use
	return 0;
}
