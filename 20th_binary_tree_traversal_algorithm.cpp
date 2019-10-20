#include <iostream>

using namespace std;


int number = 15;

//define one node
typedef struct node *treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;

//create preorder
void preorder(treePointer ptr){
	if(ptr){
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
//create inorder
void inorder(treePointer ptr){
	if(ptr){
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';		
		inorder(ptr->rightChild);
	}
}
//create inorder
void postorder(treePointer ptr){
	if(ptr){
		postorder(ptr->leftChild);	
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}	
}
int main (void){
	node nodes[number+1];
	for(int i=1; i<=number;i++){
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;		
	}
	for(int i=0; i<=number; i++){
		if(i % 2 == 0){
			nodes[i / 2].leftChild = &nodes[i];
		}else{
			nodes[i /2 ].rightChild = &nodes[i];
		}
	}
	preorder(&nodes[1]);
	printf("\n");
	inorder(&nodes[1]);
	printf("\n");
	postorder(&nodes[1]);
	printf("\n");
	
}
