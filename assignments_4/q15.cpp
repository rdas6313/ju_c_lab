#include<iostream>
#include<algorithm>
using namespace std;

class Complex{
	int real,img;
	public:
		Complex(){}
		Complex(int r,int i){
			real = r;
			img = i;
		}
		void display(){
			cout << real << "+" << img << "i";
		}
		friend Complex add(Complex c1,Complex c2);
};

Complex add(Complex c1,Complex c2){
	Complex tmp;
	tmp.real = c1.real + c2.real;
	tmp.img = c1.img + c2.img;
	return tmp;
}

int main(){
	int r,i;
	cout << "Enter complex number 1 (real,img): ";
	cin >> r >> i;
	Complex c1(r,i);
	cout << "Enter complex number 2 (real,img): ";
	cin >> r >> i;
	Complex c2(r,i);
	Complex c3 = add(c1,c2);
	cout << "(";
	c1.display();
	cout << ")";
	cout << " + ";
	cout << "(";
	c2.display();
	cout << ")";
	cout << " = ";
	cout << "(";
	c3.display();
	cout << ")";
	cout << endl;
	return 0;
}