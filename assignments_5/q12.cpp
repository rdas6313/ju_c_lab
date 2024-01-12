#include<iostream>
using namespace std;

class Shape{
	public:
		void print(){
			cout << "This is a shape!" << endl;
		}
};

class Polygon:public Shape{
	public:
		void print(){
			cout << "Polygon is a shape!" << endl;
		}
};

class Rectangle:public Polygon{
	public:
		void print(){
			cout << "Rectangle is a polygon!" << endl;
		}
};

class Triangle:public Polygon{
	public:
		void print(){
			cout << "Triangle is a polygon!" << endl;
		}
};

class Square:public Rectangle{
	public:
		void print(){
			cout << "Square is a rectangle!" << endl;
		}
};


int main(){
	Shape Shape;
	Shape.print();
	Polygon polygon;
	polygon.print();
	Rectangle rectangle;
	rectangle.print();
	Triangle triangle;
	triangle.print();
	Square square;
	square.print();
	return 0;
}