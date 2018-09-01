#include <iostream>
#include "myString.hpp"
using namespace std;

myString::myString(){
    cout<<"Default Constructor\n";
    p=nullptr;
    length=0;
}

myString::~myString(){
    cout<<"Destructor\n";
    if(p!=nullptr){
        delete []p;
        p=nullptr;
        length=0;
    }
}

size_t myString::getSizeOfConstChar(const char* tmp){
    if(tmp==nullptr){
        return 0;
    }

    size_t len;
    for(len=0;tmp[len]!='\0';len++);
    return len;
}

myString::myString(const char* tmp,size_t n){//copy only first n characters
    cout<<"Parametrized constructor, copy n characters from a const char\n";
    if(tmp==nullptr || n==0){
        p=nullptr;
        length=0;
    }
    strncpy(p,tmp,n);
    length=n;
}

char* myString::allocateMemory(size_t n){
    if(n==0){return nullptr;}
    char *p=new char[n+1];//An additional chararcter to store \0
    if(p)
        cout<<"Could not allocate memory\n";
    return p;
}

myString::myString(const myString& tmp){
    cout<<"Copy Constructor\n";
    length=tmp.length;
    p=allocateMemory(length);
    strcpy(p,tmp.p);
}

myString::myString(myString&& tmp){
    cout<<"Move Constructor\n";
    length=tmp.length;
    p=tmp.p;//Transfer ownership
    tmp.p=nullptr;
}

myString::myString(size_t n,char ch){
    cout<<"Fill Constructor\n";
    p=allocateMemory(n);
    //Handle Exception in case of failure in memmory allocation
}

int main(){
    cout<<"Hello Piyush\n";
}