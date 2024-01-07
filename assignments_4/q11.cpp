#include<iostream>
using namespace std;

void calculate(int m,char ch){
	if(ch == 'r'){
		int x = m;
		string ans = "";
		while(x > 0){
			ans += to_string(x % 10);
			x = x / 10;
		}
		cout << "Reverse of " << m << " is " << ans << endl;
	}else if(ch == 'p'){
		bool prime = true;
		for(int i=2;i<m;i++)
			if(m % i == 0){
				prime = false;
				break;
			}
		cout << "Is " << m << " a prime number: " << (prime ? "Yes" : "No") << endl;
	}
}
int main(){
	int n;
	char c;
	cout << "Enter number: ";
	cin >> n;
	cout << "Enter character: ";
	cin >> c;

	calculate(n,c);
	
	return 0;
}