#include<iostream>

using namespace std;

class StarWars
{
    public:
    int i;
    mutable int j;

    StarWars(int x, int y)    // constructor
    { 
        i = x;
        j = y;
    }

    void falcon() const  // constant function
    { 
        /* 
            can do anything but will not
            modify any data members
        */
        cout << "Falcon has left the Base\n";
    }

    void gamma()
    { 
        i++; 
    }

    void delta() const
    { 
        j++; 
    }
};


int main(){
    StarWars objOne(10,15);        // non const object
    const StarWars objTwo(20,25);      // const object

    objOne.falcon();     // No error
    objTwo.falcon();     // No error

    cout << objOne.i <<" "<< objOne.j<<endl;
    cout << objTwo.i <<" "<< objTwo.j<<endl;

    objOne.gamma();     // No error
    // objTwo.gamma();     // Compile time error

    
    objOne.delta();     // No error
    objTwo.delta();     // mutable member - No Compile time error
    
    cout<<"\nAfter updation: \n";
    cout << objOne.i <<" "<< objOne.j<<endl;
    cout << objTwo.i <<" "<< objTwo.j<<endl;
}

/*
*****Output******
Falcon has left the Base
Falcon has left the Base
10 15
20 25

After updation:
11 16
20 26

Explanation:
1. a) Since objOne is a non-const object - it can access const as well as non-const member functions.
   b) It can also update values of its member variables normally.

2. a) Since objTwo is a const object - it can only access const member functions; therefore even if we make 
      "j" mutable, objTwo cannot invoke it unless delta(), which modifies j, is const member function!!
   b) Now, since "i" is not mutable, it cannot be updated by objTwo, whether gamma() is const or not.
      But since "j" is mutable and delta() is also const, "j" is updated.
*/