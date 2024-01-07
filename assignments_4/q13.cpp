#include<iostream>
#include<algorithm>
using namespace std;

class Time{
	int hour,min,sec,day;
	public:
		friend istream& operator>>(istream&, Time&);
		friend ostream& operator<<(ostream&,Time&);
		Time operator+(Time x){
			Time tmp;
			tmp.sec = (sec + x.sec) % 60;
			//cout << "Sec: " << sec  <<" " << x.sec  << " " << (sec+x.sec)%60 << endl;
			tmp.min = (min + x.min + ((sec + x.sec) / 60)) % 60;
			tmp.hour = (hour + x.hour + (min + x.min + ((sec + x.sec) / 60)) / 60) % 24;
			tmp.day = (hour + x.hour + (min + x.min + ((sec + x.sec) / 60)) / 60) / 24;
			
			return tmp;
		}
		bool operator==(Time x){
			return hour == x.hour && min == x.min && sec == x.sec;
		}
	
};

istream& operator>>(istream& cin,Time &x){
	cin >> x.hour >> x.min >> x.sec;
	return cin;
}

ostream& operator<<(ostream& cout,Time &x){
	cout << x.hour <<" hour " << x.min << " min " << x.sec << " sec";
	return cout;
}

int main(){
	Time time1,time2;
	cout << "Enter time 1 (hour,min,sec): ";
	cin >> time1;
	cout << "Enter time 2 (hour,min,sec): ";
	cin >> time2;
	Time time3 = time1 + time2;
	cout << "Time 3: " << time3 << endl;
	cout << "Is time 1 equal with time 2: " << ((time1 == time2)? "Yes" : "No") << endl;
	return 0;
}