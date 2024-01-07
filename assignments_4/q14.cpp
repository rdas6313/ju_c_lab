#include<iostream>
#include<algorithm>
using namespace std;

class Number{
	int data;
	public:
		Number(int x){
			data = x;
		}
		void display(){
			cout << data << endl;
		}
		friend void swap(Number& num1,Number& num2);

};

void swap(Number& num1,Number& num2){
	num1.data = (num1.data ^ num2.data);
	num2.data = (num1.data ^ num2.data);
	num1.data = (num1.data ^ num2.data);
}

int main(){
	int x;
	cout << "Enter num 1: ";
	cin >> x;
	Number num1(x);
	cout << "Enter num 2: ";
	cin >> x;
	Number num2(x);
	swap(num1,num2);
	cout << "After swaping both numbers: " << endl;
	cout << "Num 1 : ";
	num1.display();
	cout << "Num 2: ";
	num2.display();
	return 0;
}