#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

//making edge class
class Edge{
	public:
		int node[2];
		int distance;
		Edge(int a, int b, int distance){
			this->node[0] = a;
			this->node[1] = b;
			this->distance = distance;
		}
		bool operator < (Edge & edge ){
			return this->distance < edge.distance;
		}
};
int main(void){
	int n = 7;
	int m = 11;
	
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));
	
	//sorting by weigh(in here distance) of edges
	sort(v.begin(), v.end());
	
	//store where each edge belongs to
	int parent[n];
	for(int i=i;i<n;i++){
		parent[i]=i;
	}
	int sum=0;
	for(int i=0; i < v.size();i++){
		if(!findParent(parent,v[i].node[0] - 1, v[i].node[1] - 1)){ //if there's no cycle
			sum += v[i].distance;
			unionParent(parent, v[i].node[0] - 1,v[i].node[1] - 1 );
		}
	}
	printf("%d",sum);
	
}
