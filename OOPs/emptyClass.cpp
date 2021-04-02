#include<iostream>

using namespace std;

class emptyClass{};

class emptyWithFunction{
    void myPrint(){
        cout<<"myPrint()\n";
    }
};

class emptyWithVirtual{
    virtual void myPrint(){
        cout<<"virtual myPrint()\n";
    }
};

int main(){
    cout<<sizeof(emptyClass)<<endl;
    cout<<sizeof(emptyWithFunction)<<endl;
    cout<<sizeof(emptyWithVirtual)<<endl;
}