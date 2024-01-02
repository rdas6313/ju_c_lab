#include<iostream>
#include<math.h>
using namespace std;

class Triangle{
	int a,b,c;
	public:
		double area();
		int perimeter(); 
		void input(){
			int x,y,z;
			cout << "3 sides of triangle(a,b,c): ";
			cin >> x >> y >> z;
			a = x;
			b = y;
			c = z;
		}
		void print(){
			cout << "Area: " << area() << endl;
			cout << "Perimeter: " << perimeter() << endl;
		}

};

double Triangle::area(){
	double s = (a+b+c)/(double)2;
	double total = s * (s-a) * (s-b) * (s-c);
	return sqrt(total);
}

int Triangle::perimeter(){
	return a+b+c;
}

int main(){
	
	Triangle triangle;
	triangle.input();
	triangle.print();
	return 0;
}