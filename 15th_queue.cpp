#include <iostream>
#include <queue>

using namespace std;

int main(void){
	queue<int> q;
	q.push(7);
	q.push(3);
	q.push(2);
	q.push(71);
	q.pop();
	q.pop();
	q.push(714);
	while(!q.empty()){
		cout << q.front() << ' ';
		q.pop();
	}
	return 0;
}
