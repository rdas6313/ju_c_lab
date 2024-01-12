#include<iostream>
using namespace std;

class Shape{
	public:
		virtual void area(){
			cout << "Area" << endl;
		}
		virtual void print(){
			cout << "This is a shape!" << endl;
		}
};

class Circle:public Shape{
	int r;
	public:
		Circle(int r){
			this->r = r;
		}

		void print(){
			cout << "Shape: Circle" << endl;
		}
		void area(){
			double a = ((double)22/7) * r * r;
			cout << "Area: " << a << endl;
		}
};

class Rectangle:public Shape{
	int l,b;
	public:
		Rectangle(int l,int b){
			this->l = l;
			this->b = b;
		}
		void print(){
			cout << "Shape: Rectangle" << endl;
		}
		void area(){
			double a = l * b;
			cout << "Area: " << a << endl;
		}
};

class Trapezoid:public Shape{
	int a,b,h;
	public:
		Trapezoid(int b1,int b2,int he){
			a = b1;
			b = b2;
			h = he;
		}
		void print(){
			cout << "Shape: Trapezoid" << endl;
		}
		void area(){
			double ar = ((a+b)*h)/2;
			cout << "Area: " << ar << endl;
		}
};

void call(Shape* shape){
	shape->print();
	shape->area();
}

int main(){
	call(new Circle(2));
	call(new Rectangle(3,4));
	call(new Trapezoid(4,3,7));
	return 0;
}