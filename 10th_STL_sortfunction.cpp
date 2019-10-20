#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string,pair<int,int> >a,
			pair<string,pair<int,int> >b){
				if(a.second.first == b.second.first){
					return a.second.second>b.second.second;
				}else
				return a.second.first>b.second.first;
			}

int main(void){
	vector<pair<string, pair<int, int> > >v;
	v.push_back(pair<string, pair<int, int> >("qwe",pair<int,int>(90,19961202)));
	v.push_back(pair<string, pair<int, int> >("qpe",pair<int,int>(90,19970517)));
	v.push_back(pair<string, pair<int, int> >("awe",pair<int,int>(80,19950222)));
	v.push_back(pair<string, pair<int, int> >("plk",pair<int,int>(80,19951103)));
	v.push_back(pair<string, pair<int, int> >("pqq",pair<int,int>(70,19991006)));
	v.push_back(pair<string, pair<int, int> >("pqq",pair<int,int>(70,19981201)));
	sort(v.begin(),v.end(),compare);
	
	for(int i=0;i<v.size();i++){
		cout << v[i].first << ' ';
	}
	return 0;
}
