#include<bits/stdc++.h>

using namespace std;

void display(){
    cout<<"normal display function\n";
}

template<typename T>
void display(){
    cout<<"general template function of type "<<typeid(T).name()<<"\n";
}

template<>
void display<char>(){
    cout<<"template specialisation for char datatype\n";
}

int main(){
    display();
    display<int>();
    display<double>();
    display<string>();
    display<char>();
}