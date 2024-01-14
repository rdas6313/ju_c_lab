#include<iostream>
using namespace std;
class Employee{
    int id;
    string name;
    double salary;
    public:
        void set(int i,string n,double sal){
            id = i;
            name = n;
            salary = sal;
        }
        double get_salary(){
            return salary;
        }
        friend ostream& operator<<(ostream&,Employee e);
};
ostream& operator<<(ostream& cout,Employee e){
    cout << e.id << " " << e.name << " " << e.salary << endl;
    return cout;
}
int main(){
    string names[5] = {"Raja","Agni","Nirupam","Puskar",
    "Firoz"};
    Employee emps[5];
    for(int i=0;i<5;i++){
        emps[i].set(i,names[i],10000+100000*i);
        cout << emps[i];
    }
    cout << "Employees who has salaries above 50000 " << endl;
    for(int i=0;i<5;i++){
        if(emps[i].get_salary() > 50000)
            cout << emps[i];
    }
    
    return 0;
}