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
    //     delete a;   // it will make the other object's pointer dangling
    // }
};

class deepCopy{
    public:
    int* a;

    deepCopy(){
        cout<<"default constructor called\n";
        a = new int;
    }

    deepCopy(deepCopy& rhs){   //overloaded copy constructor for deep copy
        cout<<"copy constructor called\n";
        //For Deep copy, first allocate the memory to the data member
        this->a = new int; //OR directly a = new int;  -- without this line, segmentation fault will occur
        // - Why? Because the default constructor is not invoked here, only copy constructor is invoked directly
        *(a) = *(rhs.a);
    }

    deepCopy& operator=(const deepCopy& rhs){
        cout<<"overloaded assignment operator called\n";

        if(this != &rhs){  // SELF ASSIGNMENT CHECK - without this, 
            delete a;  // deallocate old memory

            a = new int;  // allocate new space
            *a = *(rhs.a);  // copy value
        }

        return *this;
    }

    ~deepCopy(){
        delete a;
    }
};

int main(){
    cout<<"*****Shallow Copy*****\n";
    shallowCopy s1;
    // s1.name = "divansh";
    // shallowCopy s2 = s1;
    // cout<<s2.name<<endl;
    // s2.name = "kawatra";
    // cout<<s1.name<<endl;
    // cout<<s2.name<<endl;
    *(s1.a) = 10;
    cout<<"Value of s1.a = "<<*(s1.a)<<endl;

    cout<<"s2 object created from s1"<<endl;
    shallowCopy s2 = s1;   // shallow copying
    cout<<"Value of s2.a = "<<*(s2.a)<<endl;
    
    cout<<"Updating value of (s2.a)...."<<endl;
    *(s2.a) = 15;
    cout<<"Value of s2.a = "<<*(s2.a)<<endl;
    cout<<"Value of s1.a = "<<*(s1.a)<<endl;


    cout<<"\n*****Deep Copy*****\n";
    deepCopy d1, d3;
    *(d1.a) = 10;
    cout<<"Value of d1.a = "<<*(d1.a)<<endl;

    cout<<"d2 object created from d1"<<endl;
    deepCopy d2 = d1;  // overloaded copy constructor will be called
    cout<<"Value of d2.a = "<<*(d2.a)<<endl;
    
    cout<<"Updating value of (d2.a)...."<<endl;
    *(d2.a) = 15;
    cout<<"Value of d2.a = "<<*(d2.a)<<endl;
    cout<<"Value of d1.a = "<<*(d1.a)<<endl;

    cout<<"\n****Checking overloaded assignment operator...****\n";
    cout<<"d3 object created from d2"<<endl;
    d3 = d2;  // overloaded assignment operator will be called
    cout<<"Value of d3.a = "<<*(d3.a)<<endl;

    cout<<"Updating value of (d3.a)...."<<endl;
    *(d3.a) = 20;
    cout<<"Value of d2.a = "<<*(d2.a)<<endl;
    cout<<"Value of d3.a = "<<*(d3.a)<<endl;
}