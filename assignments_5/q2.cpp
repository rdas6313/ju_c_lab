#include<iostream>
using namespace std;
class Student{
   int roll;
   string name;
   int m1,m2,m3;
   int avg;
   public:
    void set(int r,string n,int a,int b,int c){
        roll = r;
        name = n;
        m1 = a;
        m2 = b;
        m3 = c;
    }
    void average(){
        avg = (m1+m2+m3)/3;
    }

    int get_avg(){
        return avg;
    }
    
    char grade(){
        if(avg > 80)
            return 'A';
        else if(avg > 70)
            return 'B';
        else if(avg > 60)
            return 'C';
        else if(avg > 50)
            return 'D';
        else if(avg > 40)
            return 'E';
        else
            return 'F';
    }
    friend ostream& operator<<(ostream& cout,Student s);

};
ostream& operator<<(ostream& cout,Student s){
    cout << s.roll << " " << s.name << " " << s.get_avg() << " "  << s.grade() << endl;
    return cout;
}
int main(){
    string names[5] = {"Raja","Agni","Nirupam","Puskar",
    "Firoz"};
    Student students[5];
    for(int i=0;i<5;i++){
        students[i].set(i,names[i],30+10*i,30+10*i,30+10*i);
        students[i].average();
        cout << i << " " << names[i] << " " << (30+10*i) <<" " << (30+10*i) <<" " << (30+10*i);
        cout << endl;
    }
    cout << "Output:" << endl;
    for(int i=0;i<5;i++){
        cout << students[i];
    }
    
    return 0;
}