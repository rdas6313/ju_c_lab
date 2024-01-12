#include<iostream>
using namespace std;

class Student{
	protected:
	string name;
	public:
		Student(string n){
			name = n;
		}

		virtual void print_name() = 0;
		
};

class Engineering:public Student{
	public:
		Engineering(string n):Student(n){}

		void print_name(){
			cout << name << " is a Engineering student!" << endl;
		}
};

class Medicine:public Student{
	public:
		Medicine(string n):Student(n){}
		void print_name(){
			cout << name << " is a Medical student!" << endl;
		}
};

class Science:public Student{
	public:
		Science(string n):Student(n){}
		void print_name(){
			cout << name << " is a Science student!" << endl;
		}
};

int main(){
	Student* students[3] = {new Engineering("Raja"),new Medicine("Sanchari"),new Science("Agni")};
	for(int i=0;i<3;i++)
		students[i]->print_name();
	return 0;
}