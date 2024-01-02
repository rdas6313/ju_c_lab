#include<iostream>
using namespace std;

class Leap_Year{
	int year;
	public:
		Leap_Year(int y){
			year = y;
		}
		~Leap_Year(){
			if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
				cout << year << " is leap year." << endl;
			else
				cout << year << " is not leap year" << endl;
		}
};

int main(){
	int y;
	cout << "Year: ";
	cin >> y;
	Leap_Year leap = y;
	return 0;
}