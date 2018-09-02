#include <iostream>
#include <exception>
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

myString::myString(const char* tmp){
    cout<<"Parametrized constructor\n";
    if(!tmp){
        p=nullptr;
        length=0;
    }
    size_t siz=getSizeOfConstChar(tmp);
    p=allocateMemory(siz);
    strcpy(p,tmp);
    length=siz;
}

myString::myString(const char* tmp,size_t n){//copy only first n characters
    cout<<"Parametrized constructor, copy n characters from a const char\n";
    if(tmp==nullptr || n==0){
        p=nullptr;
        length=0;
    }
    size_t siz=getSizeOfConstChar(tmp);
    if(n>siz)
        n=siz;
    p=allocateMemory(n);
    strncpy(p,tmp,n);
    length=n;
}

char* myString::allocateMemory(size_t n){
    if(n==0){return nullptr;}
    char *p;
    try{
    p=new char[n+1];//An additional chararcter to store \0
    }
    catch(bad_alloc &ex){
        cout<<"Could not allocate memory\n";
        p=nullptr;
    }
    return p;
}

myString::myString(const myString& tmp){
    cout<<"Copy Constructor\n";
    length=tmp.length;
    p=allocateMemory(length);
    strcpy(p,tmp.p);
}

myString::myString (const myString& str, size_t pos, size_t len){
    cout<<"Substring Constructor\n";
    if(pos+len > str.length -1)
        len=str.length-1;
    else len+=pos;

    p=allocateMemory(len-pos+1);
    for(int i=pos;i<=len;i++){
        p[i-pos]=str.p[i];
    }
    p[len+1-pos]='\0';
    length=len-pos;
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
    if(!p){
        bad_alloc ob;
        throw ob;
    }
    for(int i=0;i<n;i++){
        p[i]=ch;
    }
    p[n]='\0';
    length=n;
}

myString::operator const char * () {
    return const_cast<const char*>(p);
}

myString& myString::operator = (const myString& ob){
    cout<<"String copy assignment operator\n";
    if(&ob == this){
        return *this;
    }

    if(p){
        delete []p;
    }
    p=allocateMemory(ob.length);
    strcpy(p,ob.p);
    length=ob.length;
}

myString& myString::operator = (const char *tmp){
    cout<<"Char* copy assignment operator\n";
    if(p){
        delete []p;
    }

    if(!tmp){
        p=nullptr;
        length=0;
        return *this;
    }
    length=getSizeOfConstChar(tmp);
    p=allocateMemory(length);
    strcpy(p,tmp);
    return *this;
}

myString& myString::operator = (myString&& obj){
    cout<<"Move Assignment\n";
    if(p){
        delete []p;
    }
    length=obj.length;
    p=obj.p;//Transfer ownership
    obj.p=nullptr; 
    *this; 
}

int main(){
    myString a("Piyush Jain",6);
    cout<<static_cast<const char*>(a)<<"\n";
    myString b;
    b=a;
    cout<<static_cast<const char*>(b)<<"\n";
    b="Jain";
    cout<<static_cast<const char*>(b)<<"\n";
    b=myString("Bosch");
    cout<<static_cast<const char*>(b)<<"\n";
}