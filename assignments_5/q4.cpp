#include<iostream>
using namespace std;

class Greatest{
	int a,b,c;
	public:
		Greatest(int x,int y,int z){
			a = x;
			b = y;
			c = z;
		}
		class Big{
			public:
				int get_biggest(Greatest g){
					int a = g.a;
					int b = g.b;
					int c = g.c;
					return (a < b) ? ((c < b) ? b : c) : (( a < c) ? c : a);
				}
		} big;

};

int main(){
	Greatest g(5,10,11);
	cout << "Greatest of 5, 10, 11: " << g.big.get_biggest(g) << endl;
}