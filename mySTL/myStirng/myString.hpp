#include<string.h>

class myString{
    char *p;
    size_t length;
    public:
    static const size_t npos = -1;
    myString();
    ~myString();
    myString(const char*,int);
    myString(const myString&);
    myString(myString&&);
    myString(int,char);
    myString& operator = (const myString&);
    myString& operator = (myString&&);
    const char* c_str();
    bool operator == (const myString&);
    bool operator > (const myString&);
    bool operator < (const myString&);
    operator const char*();
    int get_length();
    char& operator[](int i);
    char& at(int i);
    myString operator + (const myString&);
    void operator +=(const myString&);
    void append(const myString&);
    void append(const char *);
    size_t find(const char*,int) const;
    myString substr (size_t pos = 0, size_t len = npos) const;
    
};