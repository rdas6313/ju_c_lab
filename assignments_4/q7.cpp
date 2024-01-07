#include<iostream>
using namespace std;
class String{
	char *data;
	int len;
	public:
		String(char *x){
			data = x;
			len = display();
		}
		int display(){
			char *tmp = data;
			int i = 0;
			while(tmp[i] != '\0')
				cout << tmp[i++];
			cout << endl;
			return i;
		}
		void join(String a,String b){
			int total_len = a.len + b.len;
			data = new char[total_len+1];
			int i = 0;
			while(i < a.len){
				data[i] = a.data[i];
				i++;
			}
			int j = 0;
			while(j < b.len){
				data[i] = b.data[j];
				i++;
				j++;
			}
			data[i] = '\0'; 
		}
};



int main(){
	String obj1("String 1: Raja");
	String obj2("String 2: Das");
	String obj3("String 3: ");
	obj3.join(obj1,obj2);
	obj3.display();
	
	return 0;
}