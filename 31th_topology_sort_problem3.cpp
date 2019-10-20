#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001

using namespace std;

class Edge{
public :
	int node;
	int time;
	Edge(int node, int time){
		this->node = node;
		this->time = time;
	}
};

int n, start, finish;
int inDegree[MAX], result[MAX], c[MAX];
vector<Edge> a[MAX];
vector<Edge> b[MAX];

void topologySort(){
	queue<int> q;
	//put the starting vetex to que
	q.push(start);
	//untill there's no left node to visit
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = 0; i < a[x].size(); i++){
			Edge y = Edge(a[x][i].node, a[x][i].time);
			if(result[y.node] <= y.time + result[x]){
				result[y.node] = y.time + result[x];
			}
			//put an element in a queue that has no incoming edge
			if(--inDegree[y.node] == 0){
				q.push(y.node);
			}
		}
	}
	//trace back the result
	int count = 0;
	q.push(finish);
	while(!q.empty()){
		int y = q.front();
		q.pop();
		for(int i = 0; i < b[y].size(); i++){
			Edge x = Edge(b[y][i].node, b[y][i].time);
			//check if its the longest way
			if(result[y] - result[x.node] == x.time){
				count++;
				//for tracing back put the element for once in a queue
				if(c[x.node] == 0){
					q.push(x.node);
					c[x.node] = 1;
				}
			}
		}
	}
	printf("%d\n%d", result[finish],count);
	
}
int main(void){
	int m; 
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int x, node, time;
		scanf("%d %d %d", &x, &node, &time);
		a[x].push_back(Edge(node,time));
		b[node].push_back(Edge(x, time));
		inDegree[node]++;
	}
	scanf("%d %d", &start, &finish);
	topologySort();
}
