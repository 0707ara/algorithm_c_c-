#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int> > a[7]; // weigh information for each edge
int d[7]; // minimum weigh

void dijkstra(int start){
	d[start] = 0;
	priority_queue<pair<int, int> > pq; //making heap structure
	pq.push(make_pair(start, 0)); 
	//using que to process by closest edges
	while(!pq.empty()){
		int current = pq.top().first;
		// put minus value to get the shortest first
		int distance = -pq.top().second;
		pq.pop();
		//if it's not the lightest weigh, skip
		if(d[current] < distance) continue;
		for(int i = 0; i < a[current].size();i++){
			//near node of selected node
			int next = a[current][i].first; 
			//calculate the weigh sum of through selected node
			int nextDistance = distance + a[current][i].second;
			//the new weight some through new node is lighter than the original weight switch to lightest one
			if(nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	} 
}
int main (void){
	for(int i = 1; i <= number; i++){
		d[i] = INF;
	}
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));
	
	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));
	
	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));
	
	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));
	
	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));
	
	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));
	
	dijkstra(1);
	
	//return result
	for(int i = 1; i <= number; i++){
		printf("%d", d[i]);
	}
}
