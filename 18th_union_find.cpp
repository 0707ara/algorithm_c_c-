#include <stdio.h>

//finding parent node
int getParent(int parent[],int x){
	if(parent[x]==x) return x;
	return parent[x] = getParent(parent, parent[x]);
}
//merge two parent nodes
int unionParent(int parent[], int a , int b) {
	a = getParent(parent,a);
	b = getParent(parent,b);
	if(a<b) parent[b] = a;
	else parent[a] = b;
}
//checking if they have same parent node

int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a == b){
		return 1;
	}
	return 0;
}

int main(void){
	int parent[11];
	for(int i=1;i<=10;i++){
		parent[i] = i;
	}
	unionParent(parent,1,2);
	unionParent(parent,2,3);
	unionParent(parent,3,4);
	unionParent(parent,5,6);
	unionParent(parent,6,7);
	unionParent(parent,7,8);
	printf("Is 1 and 5 connected? %d\n", findParent(parent,1,5));
	unionParent(parent,1,5);
	printf("Is 1 and 5 connected? %d\n", findParent(parent,1,5));
	printf("Get the parent node of 3.   %d\n", getParent(parent,3));
}
