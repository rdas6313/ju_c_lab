#include<iostream>
using namespace std;

class Mammals{
	public:
		void print_mammals(){
			cout << "I am mammal" << endl;
		}
};

class Marine{
	public:
		void print_marine(){
			cout << "I am marine animal" << endl;
		}
};

class Blue_whales:public Mammals,public Marine{
	public:
		void print_blue_whales(){
			cout << "I belong both the catagory!" << endl;
		}
};



int main(){
	Mammals mammal;
	Marine marine;
	Blue_whales whale;
	mammal.print_mammals();
	marine.print_marine();
	whale.print_blue_whales();
	whale.print_marine();
	whale.print_mammals();
	return 0;
}