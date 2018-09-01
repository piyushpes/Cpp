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
    strncpy(p,tmp,n);
}