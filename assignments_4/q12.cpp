#include<iostream>
#include<algorithm>
using namespace std;

class String{
	string data;
	public:
		String(string x){
			data = x;
		}
		String operator+(String x){
			string tmp = data + x.data;
			reverse(tmp.begin(),tmp.end());
			return String(tmp);
		}
		void display(){
			cout << data << endl;
		}
};

int main(){
	String a("ABC");
	String b("DEF");
	cout << "String 1: ";
	a.display();
	cout << "String 2: ";
	b.display();
	String c = a + b;
	cout << "concated and reverse string: ";
	c.display();
	return 0;
}