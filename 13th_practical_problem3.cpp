#include <iostream>

using namespace std;
int a[10001]; //when you declare the array as global variable, all the elements inside intiated 0
int n;

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		a[x]++;
	}	
	for(int i=0;i<10001;i++){
		while(a[i]!=0){
			printf("%d\n",i);
			a[i]--;
		}
	}
	return 0;
}
