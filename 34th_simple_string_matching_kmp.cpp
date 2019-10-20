#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern){
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for(int i = 1; i < patternSize; i++){
		while(j > 0 && pattern[i] != pattern[j]){
			j = table [j - 1];
		}
		if(pattern[i] == pattern[j]){
			table[i] = ++j;
		}
	}
	return table;
}
void KMP(string parent, string pattern){
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	for(int i = 0; i < parentSize; i++){
		while(j > 0 && parent[i] != pattern[j]){
			j = table[j - 1];
		}
		if(parent[i] == parent[j]){
			if(j == patternSize - 1){
				printf("It is found at the index %d\n", i - patternSize + 2);
				j = table[j];
			}else{
				j++;
			}
		}
	}
}

int main(void){
	string parent = "abacaabaaklsabacaabadkkabacaaba";
	string pattern = "abacaaba";
	KMP(parent, pattern);
	return 0;
}
