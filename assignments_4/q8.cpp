#include<iostream>
using namespace std;
class A{
    protected:
        int id;
    public:
        A(int i){
            id = i;
        }
        virtual ~A(){
            cout << "Destructor of A running. id: " << id << endl;
        }
};
class B:public A{
    int data;
    public:
        B(int x,int i):A(i){
            data = x;
            cout << "Parametrized constructor of B running! id: " << id << endl;
        }
        B(B &obj,int i):A(i){
            data = obj.data;
            cout << "Copy constructor of B running! id: " << id << endl;
        }

        ~B(){
            cout << "Destructor of B running. id: " << id << endl;
        }
};

int main(){
    A *p = new B(10,0);
    B o1(100,1);
    B o2(o1,2);
    delete p;
    return 0;
}