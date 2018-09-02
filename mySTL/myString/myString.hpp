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
    explicit myString(const char* tmp);
    myString(const char*,size_t);
    myString(const myString&);
    myString (const myString&, size_t, size_t len = npos);
    myString(myString&&);
    myString(size_t,char);
    myString& operator = (const myString&);
    myString& operator = (const char *);
    myString& operator = (myString&&);
    const char* c_str() const;
    bool operator == (const myString&) const;
    bool operator > (const myString&) const;
    bool operator < (const myString&) const;
    explicit operator const char*();
    size_t get_length() const;
    char& operator[](int i) const;
    char& at(int i) const;
    myString operator + (const myString&);
    void operator +=(const myString&);
    void append(const myString&);
    void append(const char *);
    size_t find(const char*,size_t);
    myString substr (size_t pos = 0, size_t len = npos) const;
    
};

#endif