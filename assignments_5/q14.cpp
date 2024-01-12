#include<iostream>
using namespace std;

class Person{
	public:
		void print_name(){
			cout << "Implementing virtual base class" << endl;
		}
		
};

class Employee:public virtual Person{};

class Student:public virtual Person{};

class Manager:public Employee,public Student{};

int main(){
	Manager m;
	m.print_name();
	return 0;
}