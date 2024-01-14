#include<iostream>
#include<fstream>
#define filename "data8.txt"
#define tempfile "temp8.txt"
using namespace std;

class Record{
	string name;
	int roll;
	public:
		Record(){}
		Record(string n,int r){
			name = n;
			roll = r;
		}
		int get_roll(){
			return roll;
		}
		void set_name(string n){
			name = n;
		}
		friend ostream& operator<<(ostream&,Record);
		friend istream& operator>>(istream&,Record&);

};

ostream& operator<<(ostream& cout, Record rec){
	cout << rec.roll << " " << rec.name << endl;
	return cout;
}

istream& operator>>(istream& cin, Record &rec){
	cin >> rec.roll >> rec.name;
	return cin;
}


void add(){
	ofstream out;
	out.open(filename,ios::app);
	if(!out){
		cout << "Error opeing file " << filename << endl;
		return;
	}
	string name;
	int roll;
	cout << "Name: ";
	cin >> name;
	cout << "Roll: ";
	cin >> roll;
	Record rec(name,roll);
	//out.write((char*)&rec,sizeof(rec));
	out << rec;
	out.close();
}

void view(){
	ifstream in;
	in.open(filename,ios::in);
	if(!in){
		cout << "Error opeing file " << filename << endl;
		return;
	}
	Record rec("x",0);
	while(!in.eof()){
		in >> rec;
		if(in.eof())
			break;		
		cout << rec; 
	}
	in.close();
	
}



void search(){
	int roll;
	cout << "Roll: ";
	cin >> roll;

	ifstream in;
	in.open(filename,ios::in);
	if(!in){
		cout << "Error opeing file " << filename << endl;
		return;
	}
	cout << "Search Result: " << endl;
	Record rec("x",-1);
	bool found = false;
	while(!in.eof()){
		in >> rec;
		if(in.eof())
			break;
		if(rec.get_roll() == roll){
			cout << rec;
			found = true;
		}
	}
	if(!found){
		cout << "Not found!" << endl;
	}
	in.close();

}

void update(){
	int roll;
	cout << "Roll: ";
	cin >> roll;

	ifstream in;
	in.open(filename,ios::in);
	if(!in){
		cout << "Error opeing file " << filename << endl;
		return;
	}
	fstream fout;
	fout.open(tempfile,ios::out | ios::in | ios::trunc);
	if(!fout){
		cout << "Error opeing file " << tempfile << endl;
		return;
	}
	Record rec("x",-1);
	while(!in.eof()){
		in >> rec;
		if(in.eof())
			break;
		if(rec.get_roll() == roll){
			string name;
			cout << "Name: ";
			cin >> name;
			rec.set_name(name);
		}
		fout << rec;
	}
	in.close();
	ofstream out(filename);
	if(!out){
		cout << "Error opeing file " << filename << endl;
		return;
	}
	fout.seekg(0,ios::beg);
	while(!fout.eof()){
		fout >> rec;
		if(fout.eof())
			break;
		out << rec;
	}
	out.close();
	fout.close();
	cout << "Successfully updated!" << endl;

}

void del(){
	int roll;
	cout << "Roll: ";
	cin >> roll;

	ifstream in;
	in.open(filename,ios::in);
	if(!in){
		cout << "Error opeing file " << filename << endl;
		return;
	}
	fstream fout;
	fout.open(tempfile,ios::out | ios::in | ios::trunc);
	if(!fout){
		cout << "Error opeing file " << tempfile << endl;
		return;
	}
	Record rec("x",-1);
	while(!in.eof()){
		in >> rec;
		if(in.eof())
			break;
		if(rec.get_roll() == roll)
			continue;
		fout << rec;
	}
	in.close();
	ofstream out(filename);
	if(!out){
		cout << "Error opeing file " << filename << endl;
		return;
	}
	fout.seekg(0,ios::beg);
	while(!fout.eof()){
		fout >> rec;
		if(fout.eof())
			break;
		out << rec;
	}
	out.close();
	fout.close();
	cout << "Successfully deleted!" << endl;
	
}

int main(){
	cout << "1. Add new Record" << endl;
	cout << "2. View all Record" << endl;
	cout << "3. Delete a Record" << endl;
	cout << "4. Search Record" << endl;
	cout << "5. Update Record" << endl;
	cout << "Choose: ";
	int choice;
	cin >> choice;
	switch(choice){
		case 1:
			add();
			break;
		case 2:
			view();
			break;
		case 3:
			del();
			break;
		case 4:
			search();
			break;
		case 5:
			update();
			break;
	}
	return 0;
}