#include<iostream>

using namespace std;

int main(){
    const int x = 10;
    cout<<"Value of const x = "<<x<<endl;

    int* ptr = (int*)&x;
    cout<<"Value of *ptr = "<<*ptr<<endl;

    cout<<"Address of x: "<<&x<<endl;
    cout<<"Address of *ptr: "<<&(*ptr)<<endl;


    cout<<"Updating value of *ptr...."<<endl;
    cout<<"Value of *ptr = "<<*ptr<<endl;
    cout<<"Changed the value of \"so called\" const variable x to "<<x<<endl;

    cout<<"Address of x: "<<&x<<endl;
    cout<<"Address of *ptr: "<<&(*ptr)<<endl;

    return 0;
}

/*
******Output******
Value of const x = 10
Value of *ptr = 10
Address of x: 0x61fe14
Address of *ptr: 0x61fe14
Updating value of *ptr....
Value of *ptr = 20
Changed the value of "so called" const variable x to 10
Address of x: 0x61fe14
Address of *ptr: 0x61fe14

Questions:
The above method of changing the value of a const variable works in C and not in C++.(WHY ???)
Also even though the address of x and (*ptr) is the same, there values are different. (HOW??, WHY??)
*/