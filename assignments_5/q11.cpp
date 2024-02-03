#include<iostream>
#include<string>
using namespace std;
class Marks{
    protected:
        int roll;
        string name;
        int marks;
    public:
        static int number;
        Marks(string n,int m){
            number++;
            roll = number;
            name = n;
            marks = m;
        }
        int get_marks(){
            return marks;
        }
        string get_name(){
            return name;
        }
        int get_roll(){
            return roll;
        }

};

int Marks::number = 0;

class Physics:public Marks{
    public:
        Physics(string n,int m):Marks(n,m){
        }
};

class Chemistry:public Marks{
    public:
        Chemistry(string n,int m):Marks(n,m){
        }
};

class Mathematics:public Marks{
    public:
        Mathematics(string n,int m):Marks(n,m){
        }
};

int main(){
    Physics* phyStudents[] = {new Physics("Raja",50),new Physics("Puskar",90)};
    Chemistry* chmStudents[] = {new Chemistry("Sanchari",99),new Chemistry("Toushique",90)};
    Mathematics* mathStudents[] = {new Mathematics("Agni",90),new Mathematics("Rahul",67)};
    int phyTotal = 0, cheTotal = 0, mathTotal = 0;
    for(int i=0;i<2;i++){
        phyTotal += phyStudents[i]->get_marks();
        cheTotal += chmStudents[i]->get_marks();
        mathTotal += mathStudents[i]->get_marks();
    }
    cout << "Physics class students with their marks:" << endl;
    for(int i=0;i<2;i++){
        cout << phyStudents[i]->get_roll() << " " << phyStudents[i]->get_name() << " " << phyStudents[i]->get_marks() << endl;
    }

    cout << "Total marks in physics class: " << phyTotal << endl;
    cout << "Avg marks in physics class: " << ((double)phyTotal/2) << endl;

    cout << endl;
    cout << "Chemistry class students with their marks:" << endl;
    for(int i=0;i<2;i++){
        cout << chmStudents[i]->get_roll() << " " << chmStudents[i]->get_name() << " " << chmStudents[i]->get_marks() << endl;
    }
    cout << "Total marks in Chemistry class: " << cheTotal << endl;
    cout << "Avg marks in Chemistry class: " << ((double)cheTotal/2) << endl;


    cout << endl;
    cout << "Math class students with their marks:" << endl;
    for(int i=0;i<2;i++){
        cout << mathStudents[i]->get_roll() << " " << mathStudents[i]->get_name() << " " << mathStudents[i]->get_marks() << endl;
    }
    cout << "Total marks in Math class: " << mathTotal << endl;
    cout << "Avg marks in Math class: " << ((double)mathTotal/2) << endl;
    return 0;
}
