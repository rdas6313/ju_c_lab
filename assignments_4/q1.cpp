#include<iostream>
using namespace std;
class Shape{
	protected:
		const double pi;
	public:
		Shape():pi(3.14){}
};

class Circle:public Shape{
	private:
		double radius;
	public:
		Circle(double r){
			radius = r;
		}
		void print_area(){
			double area = pi * radius * radius;
			cout << "Radius of circle: " << area << endl; 
		}
};
int main(){
	int r;
	cout << "Radius: ";
	cin >> r;
	Circle c = Circle(r);
	c.print_area();
	return 0;
}