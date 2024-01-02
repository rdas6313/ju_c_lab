#include<iostream>
using namespace std;

class Complex{
	int real,img;
	public:
		Complex(){
			real = 0;
			img = 0;
		}
		Complex(int r){
			real = r;
			img = 0;
		}
		Complex(int r,int i){
			real = r;
			img = i;
		}
		void sum(const Complex &obj){
			real += obj.real;
			img += obj.img;
		}
		void show(){
			cout << real << "+" << img << "i";
		}

};

int main(){
	Complex c1(2,3),c2 = 1;
	cout << "(";
	c1.show();
	cout << ") + ";
	cout << "(";
	c2.show();
	cout << ") = ";
	c2.sum(c1);
	c2.show();
	cout << endl;
	return 0;
}