#include<iostream>
using namespace std;

inline int square(int x){
	return x * x;
}
int main(){
	int y;
	cout << "Number: ";
	cin >> y;
	cout << "(" << y << ")^2 = " << square(y) << endl;
		return 0;
}