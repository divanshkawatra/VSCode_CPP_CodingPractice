#include<bits/stdc++.h>

using namespace std;

template<class T> //template<typename T>
T getMax(T a, T b){
    return (a>b)?a:b;
}

int main(){
    int a = 10, b= 20;
    char c1 = 'z', c2 = 'b';

    cout<<"a = "<<a<<", b = "<<b<<"\n";
    cout<<"c1 = "<<c1<<", c2 = "<<c2<<"\n";

    cout<<"Larger of a and b: "<<getMax<int>(a,b)<<"\n";
    cout<<"Larger of c1 and c2: "<<getMax<char>(c1,c2)<<"\n";

    
    cout<<"Larger of int(c1) and int(c2): "<<getMax<int>(c1,c2)<<"\n";
    cout<<"Larger of char(a) and char(b): "<<getMax<char>(a,b)<<"\n";
}