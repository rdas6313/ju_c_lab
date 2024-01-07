#include<iostream>
using namespace std;

int volume(int a){ // cube
	return a * a *a;
}
int volume(int l,int b,int h){ // cuboid
	return l * b * h;
}
double volume(int r,int h){ // cone
	return ((double)1/3) * ((double)22/7) * r * r * h;
}
double volume(char x,int r,int h){ // cylinder
	return ((double)22/7) * r * r * h;
}
double volume(char x,int r){ // sphere
	return ((double)4/3) * ((double)22/7) * r * r * r;
}

int main(){
	
	cout << "1. Volume of cube" << endl;
	cout << "2. Volume of cuboid" << endl;
	cout << "3. Volume of cone" << endl;
	cout << "4. Volume of cylinder" << endl;
	cout << "5. Volume of sphere" << endl;
	int choice,a,b,c;
	cout << "choose: ";
	cin >> choice;
	switch(choice){
		case 1:
			cout << "Cube edge length: ";
			cin >> a;
			cout << "Volume of cube: " << volume(a) << endl;
			break;
		case 2:
			cout << "Cuboid length,breadth,height: ";
			cin >> a >> b >> c;
			cout << "Volume of Cuboid: " << volume(a,b,c) << endl;
			break;
		case 3:
			cout << "Cone radius,height: ";
			cin >> a >> b;
			cout << "Volume of cone: " << volume(a,b) << endl;
			break;
		case 4:
			cout << "Cylinder radius,height: ";
			cin >> a >> b;
			cout << "Volume of cylinder: " << volume(' ',a,b) << endl;
			break;
		case 5:
			cout << "Sphere radius: ";
			cin >> a;
			cout << "Volume of sphere: " << volume(' ',a) << endl;
			break;
		default:
			cout << "Invalid choice!" << endl;
	}
	return 0;	
}