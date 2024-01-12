#include<iostream>
using namespace std;

class Rectangle{
	int length,breadth;
	public:
		void set(int l,int b){
			length = l;
			breadth = b;
		}
		bool is_equal(){
			return length == breadth;
		}
		friend ostream& operator<<(ostream&, Rectangle);
};


ostream& operator<<(ostream& cout,Rectangle rect){
	cout << "Length " << rect.length << " Breadth " << rect.breadth << endl;
	return cout;
}

int main(){
	Rectangle rects[5];
	for(int i=0;i<4;i++){
		rects[i].set(i,i*2);
	}
	rects[4].set(100,100);
	for(int i=0;i<5;i++){
		cout << rects[i];
	}
	cout << "Length and breadth equal rectangle:- " << endl;
	for(int i=0;i<5;i++){
		if(rects[i].is_equal())
			cout << rects[i];
	}
}