#include<iostream>
using namespace std;

class Calculator{
	int a,b;
	public:
		Calculator(int x,int y){
			a = x;
			b = y;
		}
		class Addition{
			public:
				int add(Calculator c){
					return c.a + c.b;
				}
		} add;

		class Substraction{
			public:
				int sub(Calculator c){
					return c.a - c.b;
				}
		} sub;

		class Multiplication{
			public:
				int mul(Calculator c){
					return c.a * c.b;
				}
		} mul;

		class Division{
			public:
				int div(Calculator c){
					return c.a / c.b;
				}
		} div;
		
};


int main(){
	int a,b;
	cout << "Two numbers: ";
	cin >> a >> b;
	Calculator c(a,b);
	cout << "Addition: " << c.add.add(c) << endl;
	cout << "Substraction: " << c.sub.sub(c) << endl;
	cout << "Multiplication: " << c.mul.mul(c) << endl;
	cout << "Division: " << c.div.div(c) << endl;
	return 0;
}