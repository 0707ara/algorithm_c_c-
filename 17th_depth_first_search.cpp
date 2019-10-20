#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

void dfs(int x){
	if(c[x]) return;
	c[x] = true; 
	cout << x << ' ';
	for(int i=0; i<a[x].size();i++){ //visit the near node 
		int y=a[x][i];
		dfs(y); //within near node call the dfs function
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
	dfs(1); //start point is 1
	return 0;
}
