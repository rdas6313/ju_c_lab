#include<iostream>
using namespace std;

class Circle{
	int r;
	double area(){
		return ((double)22/7) * r * r;
	}
	public:
		Circle(int x){
			r = x;
		}
		class Print{
			public:
				void print(Circle c){
					cout << c.area() << endl;
				}
		} out;
};


int main(){
	int r;
	cout << "Radius: ";
	cin >> r;
	Circle c(r);
		cout << "Area: ";
	c.out.print(c);
	return 0;
}