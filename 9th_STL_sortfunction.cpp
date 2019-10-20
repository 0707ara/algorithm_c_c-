#include <iostream>
#include <algorithm>

using namespace std;
class Student{
	public:
		string name;
		int score;
		Student(string name, int score){
			this->name=name;
			this->score=score;
		}
		bool operator < (Student & student){
			return this->score < student.score;
		}
};

bool compare(int a, int b){
	return a>b;
	//a<b ascening order
}
int main(void){
	Student students[] ={
		Student("NBD",90),
		Student("LSO",80),
		Student("LHW",100),
		Student("KJK",29),
		Student("JHY",88)
	};
	sort(students,students+5);
	for(int i=0; i<5;i++){
		cout<< students[i].name <<' ';
	}
}
