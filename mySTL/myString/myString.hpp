#ifndef MYSTRING_PROTO
#define MYSTRING_PROTO
#include<string.h>

class myString{
    char *p;
    size_t length;
    size_t getSizeOfConstChar(const char*);
    char* allocateMemory(size_t);
    public:
    static const size_t npos = -1;
    myString();
    ~myString();
    myString(const char*,size_t);
    myString(const myString&);
    myString(myString&&);
    myString(size_t,char);
    myString& operator = (const myString&);
    myString& operator = (myString&&);
    const char* c_str();
    bool operator == (const myString&);
    bool operator > (const myString&);
    bool operator < (const myString&);
    operator const char*();
    size_t get_length() const;
    char& operator[](int i);
    char& at(int i);
    myString operator + (const myString&);
    void operator +=(const myString&);
    void append(const myString&);
    void append(const char *);
    size_t find(const char*,int) const;
    myString substr (size_t pos = 0, size_t len = npos) const;
    
};

#endif