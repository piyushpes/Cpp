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

    if(len==npos || pos+len > str.length -1)
        len=str.length;
    else len+=pos;
    //cout<<len;
    p=allocateMemory(len-pos);
    for(int i=pos;i<len;i++){
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

const char* myString::c_str() const{
    return const_cast<const char*>(p);
}

bool myString::operator == (const myString& ob) const{
    return strcmp(p,ob.p)? false:true;
}

bool myString::operator < (const myString& ob) const{
    return (strcmp(p,ob.p)<0)? true:false;
}

bool myString::operator > (const myString& ob) const{
    return (strcmp(p,ob.p)>0)? true:false;
}

size_t myString::get_length() const{
    return length;
}

char& myString::operator[](int i) const{//if i> lenght then the last charcter reference is returned
    if(i>=length){
        return p[length-1];
    }
    return p[i];
}

char& myString::at(int i) const{
    return (*this)[i];
}

myString myString::operator + (const myString& obj){
    myString tmp;
    tmp.length=length+obj.length;
    tmp.p=allocateMemory(tmp.length);
    strcpy(tmp.p,p);
    strcat(tmp.p,obj.p);
    return tmp;
}

void myString::operator +=(const myString& obj){
    //length=length+obj.length;
    //char *tmp=allocateMemory(length);
    //strcpy(tmp,p);
    //strcat(tmp,obj.p);
    //delete []p;
    //p=tmp;
    (*this)=(*this)+obj;
}

void myString::append(const myString& obj){
    *this += obj;
}

void myString::append(const char * ptr){
    *this += myString(ptr);
}

size_t myString::find(const char* ptr,size_t n){
    size_t charSize=getSizeOfConstChar(ptr);
    size_t pos=npos;
    if(n>=length || (charSize + n)>length)
        return npos;

    for(int i=n;i<length-charSize+1;i++){
        if(p[i]==ptr[0]){
            pos=i;
            int j=1;
            while(j<charSize){
                if(ptr[j]!=p[i+j]){
                    break;
                }
                j++;
            }
            if(j==charSize){
                return pos;
            }
            
        }
    }
    return npos;
}

myString myString::substr (size_t pos, size_t len) const{
    if(pos>=length)
        return myString();
    if(len==npos || (pos+len) >= length){
        len=length-pos;
    }
    return myString(*this,pos,len);
}

myString::iterator myString::begin(){
    myString::iterator it(p);
    return it;
}

myString::iterator myString::end(){
    myString::iterator it(p + length);
    return it;
}

int main(){
    myString a("Piyush Jain");
    
    
    cout<<"\n";

    for(auto it=a.begin();it!=a.end();++it)
        cout<<*it;

    cout<<"\n";

}