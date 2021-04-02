#include<iostream>
#include<vector>

using namespace std;

class shallowCopy{
    public:
    //char* name;
    int* a;
    // shallowCopy(int n=10){         //not working with char*
    //     name = new char[n];
    //     name = "default";
    // }
    shallowCopy(){
        a = new int;
    }

    // ~shallowCopy(){
    //     delete a;
    // }
};

class deepCopy{
    public:
    int* a;

    deepCopy(){
        a = new int;
    }

    deepCopy(deepCopy& rhs){   //overloaded copy constructor for deep copy
        cout<<"copy constructor called\n";
        this->a = new int; //OR directly a = new int;
        *(a) = *(rhs.a);
    }

    deepCopy& operator=(const deepCopy& rhs){
        cout<<"overloaded assignment operator called\n";
        *a = *(rhs.a);

        return *this;
    }

    ~deepCopy(){
        delete a;
    }
};

int main(){
    cout<<"Shallow Copy\n";
    shallowCopy s1;
    // s1.name = "divansh";
    // shallowCopy s2 = s1;
    // cout<<s2.name<<endl;
    // s2.name = "kawatra";
    // cout<<s1.name<<endl;
    // cout<<s2.name<<endl;
    *(s1.a) = 10;
    shallowCopy s2 = s1;
    cout<<*(s2.a)<<endl;
    *(s2.a) = 15;
    cout<<*(s1.a)<<endl;
    cout<<*(s2.a)<<endl;

    cout<<"\nDeep Copy:\n";
    deepCopy d1, d3;
    *(d1.a) = 10;
    deepCopy d2 = d1;
    cout<<*(d2.a)<<endl;
    *(d2.a) = 15;
    cout<<*(d1.a)<<endl;
    cout<<*(d2.a)<<endl;

    d3 = d2;
    cout<<*(d3.a)<<endl;

}