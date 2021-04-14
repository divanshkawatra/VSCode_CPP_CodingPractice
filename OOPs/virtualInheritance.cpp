#include<iostream>

using namespace std;

/*
class A{
    public:
        void show(){
            cout<<"From class A !\n";
        }
};

class B:public A{
};

class C:public A{
};

class D:public B,C{
};

int main(){
    D d;
    d.show();  //compilation error, ambiguous call to show()
}

Explanation:
Diamond Problem:
There is ambiguity, d.show() refers to show() inherited from B or C.
Can be resolved in two ways:
1. virtual inheritance:
        class B: virtual public A{
        };

        class C:virtual public A{
        };

2. Explicitly mentioning show function belongs to which class in function call:
        d.B::show();
        d.C::show();
*/

//In below program, new ambiguity is introduced after resolving "Diamond problem" by virtual inheritance.
//New Problem: both classes B and C, contains a similar signature function display()
class A{
    public:
        void show(){
            cout<<"From class A !\n";
        }
};

class B:virtual public A{
    public:
        void display(){
            cout<<"class B display()\n";
        }
};

class C:virtual public A{
    public:
        void display(){
            cout<<"class C display()\n";
        }
        void display(int x){
            cout<<"class C parametrised display()\n";
        }
};

class D:public B, public C{  //public B,C - here C is privately inherited by default
};

int main(){
    D d;
    d.show();  //now no compilation error, resolved using virtual inheritance

    d.B::display();
    d.C::display();

    int x = 5;
    // d.display(x); //compilation error, ambiguous call to show() -- even though it shouldn't be
    d.C::display(x);
}