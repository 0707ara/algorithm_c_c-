#include <iostream>
#include <algorithm>

using namespace std;

string a [20000];
int n;

bool compare(string a, string b){
	//order by lenghth of words
	if(a.length() < b.length()){
		return 1; //shorter one comes first
	}else if(a.length()>b.length()){
		return 0;
	}else{
		return a<b;//if variable type is string a<b means alphabetical order
	}
}

int main (void){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,compare);
	for(int i=0; i<n;i++){
		//by using sorted array u can use if function a[i]==a[i+1] to dicern it's same or not
		if(i>0&&a[i]==a[i-1]){
			continue;
		}else{
			cout << a[i] <<'\n';
		}			
	}return 0;
}
