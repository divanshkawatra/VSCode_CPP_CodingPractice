#include<iostream>

using namespace std;

class A{
    public:
        virtual void display(){
            cout<<"Inside class A\n";
        }
};

class B: public A{
    public:
        void display(){
            cout<<"Inside class B\n";
        }
};

class C: public B{
    public:
        // void display(){
        //     cout<<"Inside class C\n";
        // }
};

int main(){
    A* b = new B;
    b->display();

    A* c = new C;
    c->display();
}

/* 
*****Output*****
Inside class B
Inside class C
i.e. 
display() is defined as virtual in only class A(and not in class B), still when C is overriding display(), correct function is called.

When C does not override display(), the last class that overridden the function, that class's version is invoked.
*/