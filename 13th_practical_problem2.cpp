#include <iostream>
#include <algorithm>

using namespace std;

string a [20000];
int n;

int getSum(string a){
	int length = a.length(), sum=0;
	for(int i=0;i<length;i++){
		if(a[i] - '0' <= 9 && a[i] - '0' >= 0){//sum when it is number
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool compare(string a, string b){
	//order by lenghth of words
	if(a.length() < b.length()){
		return 1; //shorter one comes first
	}else if(a.length()>b.length()){
		return 0;
	}else{ //if the length is same
		int aSum = getSum(a);
		int bSum = getSum(b);
		//if the number among the total string is diff
		if(aSum != bSum){
			return aSum < bSum;
		} else {
			return a<b;
		}
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
