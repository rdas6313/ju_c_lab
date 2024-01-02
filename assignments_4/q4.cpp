#include<iostream>
using namespace std;
class Pattern{
	public:
		void print_pattern(int row){
			int col = row * 2-1;
			for(int i=0;i<row;i++){
				print(' ',i);
				print('*',col-2*i);
				print(' ',i);
				cout << endl;
			}
		}
		void print(char x,int no_of_times){
			for(int i=0;i<no_of_times;i++){
				cout << x;
			}
		}
};
int main(){
	Pattern p;
	int x;
	cout << "No of rows: ";
	cin >> x;
	p.print_pattern(x);
	return 0;
}