#include<iostream>
#include<fstream>
using namespace std;

int main(){
	string file_name = "input7.txt";
	ifstream in;
	in.open(file_name,ios::in | ios::binary);
	if(!in){
		cout << "Error opening file " << file_name << endl;
		return 0;
	}
	char x;
	int line = 0, words = 0, chars = 0;
	cout << "File content: " << endl;
	while(!in.eof()){
		x = in.get();		
		cout << x;
		if(x == ' ' || x == '\n' || x == EOF){
			words++;
			if(x == '\n' || x == EOF)
				line++;
		}
		else
			chars++;
	}
	cout << endl;
	in.close();
	cout << "No of lines: " << line << endl;
	cout << "No of words: " << words << endl;
	cout << "No of chars: " << chars << endl;
	return 0;
}