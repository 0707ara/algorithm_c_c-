#include <iostream>
#include <vector>
#include <stack>
#define MAX 10001


using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector <int> > SCC; 
stack<int> s;

//DFS is excuted number of vertex
int dfs(int x){
	d[x] = ++id; //allocate each vertex their own unique number
	s.push(x);   //put oneself in the stack
	
	int parent = d[x];
	for(int i = 0; i < a[x].size(); i++){
		// y is near vertex
		int y = a[x][i]; 
		// unchecked vertex
		if(d[y] == 0) parent = min(parent, dfs(y));
		//checked but not proceeed
		else if(!finished[y]) parent = min(parent, d[y]);
	}
	//if the parentnode turned out to itself 
	if(parent == d[x]){
		vector<int> scc;
		while(1){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if(t == x) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main(void){
	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);
	for(int i = 1; i <= v; i++) {
		if(d[i] == 0) dfs(i);
	}
	printf("Number of SCC : %d \n", SCC.size());
	for(int i = 0; i < SCC.size(); i++){
		printf("%d round of SCC ", i + 1);
		for(int j = 0; j < SCC[i].size(); j++) {
			printf("%d ", SCC[i][j]);
		}
		printf("\n");
	} //O(V+E) 
	return 0; 
}
