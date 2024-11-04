# ifndef MYSTRING_H
# define MYSTRING_H

#include <iostream>
using namespace std;
// TODO: Implement this header file
class MyString {
    public:
        MyString();
        MyString(const MyString& str);
        MyString(const char* str);
        ~MyString();

        void resize(size_t n);
        size_t capacity() const;
        size_t size() const;
        size_t length() const;
        char* data() const;
        bool empty() const;
        const char& front() const;
        const char& at(size_t pos) const;
        void clear();

        friend ostream& operator<<(ostream& out, const MyString& str);
        MyString& operator=(const MyString& str);
        MyString& operator+=(const MyString& str);
        size_t find(const MyString& str, size_t post = 0) const;
        bool operator==(const MyString& str) const;
        MyString& operator+(const MyString& str);
    private:
        size_t stringSize;
        size_t stringCapacity;
        char* character;
};

#endif