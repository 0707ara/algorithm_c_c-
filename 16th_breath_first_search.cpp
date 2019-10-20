#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int number = 7;
int c[7]; //checked array
vector<int> a[8]; //put the 8 to use the index of array from 1 not 0;
				  // make an array that can contain vector

void bfs(int start){
	queue<int> q;
	q.push(start); //push the startpoint to queue
	c[start] = true; //checked
	while(!q.empty()){
		int x = q.front(); //take out the element from queue and put it in the variable x
		q.pop(); 
		printf("%d ",x);
		for(int i=0; i < a[x].size();i++){ //checking the near node around current node 
			int y = a[x][i];
			if(!c[y]){ //if the near node is not checked
			q.push(y); //put the element in the queue
			c[y] = true; //change the status as checked 				
			}
		}		
	}
}

int main (void){
	a[1].push_back(2);
	a[2].push_back(1);
	//connect 1 and 2
	a[1].push_back(3);
	a[3].push_back(1);
	//connect 1 and 3
	a[2].push_back(3);
	a[3].push_back(2);
	//connect 2 and 3
	a[2].push_back(4);
	a[4].push_back(2);
	//connect 2 and 4
	a[2].push_back(5);
	a[5].push_back(2);
	//connect 2 and 5
	a[3].push_back(6);
	a[6].push_back(3);
	//connect 3 and 6
	a[3].push_back(7);
	a[7].push_back(3);
	//connect 3 and 7
	a[4].push_back(5);
	a[5].push_back(4);
	//connect 4 and 5
	a[6].push_back(7);
	a[7].push_back(6); 
	//connect 6 and 7
	bfs(1); //start point is 1
	return 0;
}
