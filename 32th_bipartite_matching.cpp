#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n = 3, m; //m for number of edge

//if the matching is succeed return true, fail return false
bool dfs(int x){
	//try to search every single possible choices that the vertex can choose
	for(int i = 0; i < a[x].size();i++){
		int t = a[x][i];
		//if the node is proceeded no reason to check again 
		if(c[t])continue;
		c[t] = true;
		//if the node is empty or there's a chance to choose other node
		if(d[t] == 0 || dfs(d[t])){
			d[t] = x;
			return true;
		}
	}
	return false;
}
int main(void) {
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);
	int count = 0;
	for(int i = 1; i <= n; i++) {
		//every time the function match, intialize array c with false  
		fill(c, c + MAX, false); 
		//if the new match is made, count++ to see
		if(dfs(i)) count++;
	}
	printf("%d number of matching was made \n", count);
	for(int i = 1; i <= 100; i++) {
		if(d[i] != 0) {
			printf("%d -> %d\n", d[i], i);
		}
	}
	return 0;
}
