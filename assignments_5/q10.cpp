#include<iostream>
using namespace std;

class Fruit{
	int count;
	public:
		Fruit(int c){
			count = c;
		}
		int get_total_fruit(){
			return count;
		}

};

class Mangoes;

class Apples:public Fruit{
	public:
		Apples(int c):Fruit(c){}
		friend int add(const Apples,const Mangoes);

};

class Mangoes:public Fruit{
	public:
		Mangoes(int c):Fruit(c){}
		friend int add(const Apples,const Mangoes);
};

int add(Apples a,Mangoes m){
	return a.get_total_fruit() + m.get_total_fruit();
}

int main(){
	Apples a(10);
	Mangoes m(5);
	cout << "No of apples: " << a.get_total_fruit() << endl;
	cout << "No of Mangoes: " << m.get_total_fruit() << endl;
	cout << "Total number of Fruits: " << add(a,m) << endl;
	return 0;
}