#include <stdio.h>

int number = 9;
int heap[9] = {7,6,5,8,3,5,9,1,6};

int main(void){//make the max heap
	for(int i=0;i<number;i++){
			printf("%d ",heap[i]);
		}printf("\n");
	for(int i=1;i<number;i++){
		int c=i;//child node
		do{
			int root = (c-1)/2; //parent node
			if(heap[root]<heap[c]){
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			} c=root; //go child node and do the same for each child nodes 	
		}while(c!=0);
	}
	for(int i=0;i<number;i++){
		printf("%d ",heap[i]);
	}printf("\n"); //heap is made
	//reducing the size and make a heap	(sorting)
	for(int i=number-1;i>=0;i--){
		int temp = heap[0]; //to get sorted result heap[0]is now the biggest move it to the last one
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c=1;
		do{
			c=2*root +1;
			//find bigger one between two child
			//c<i-1 so that child node cannot go further then the current parent-child node
			if(heap[c] < heap[c+1] && c<i-1){
				c++;
			}
			//if the root is less than child swap
			if(heap[root]<heap[c] && c<i ){
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			} root = c;
		}while(c<i);
	}
	for(int i=0;i<number;i++){
		printf("%d ",heap[i]);
	}
}
