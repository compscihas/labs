// TODO: Implement this source file
# include <iostream>
# include <stdexcept>
# include "MyString.h"

using namespace std;

MyString::MyString() : stringSize(0), stringCapacity(1), character(new char[1]) {
    character[stringSize] = '\0';
}
MyString::MyString(const MyString& str) : stringSize(str.size()), stringCapacity(str.capacity()), character(new char[str.capacity()]){
    for(size_t count = 0; count < stringSize; ++count){
        character[count] = str.character[count];
    }
    character[stringSize] = '\0';
}
MyString::MyString(const char* str) : stringSize(0), stringCapacity(1), character(0) {
    size_t count = 0;
    while(str[count] != '\0'){
        count++;
    }
    stringSize = count;
    stringCapacity = count + 1;
    delete [] character;
    character = new char[stringCapacity];
    for(size_t count = 0; count < stringSize; count++){
        character[count] = str[count];
    }
    character[stringSize] = '\0';
}

MyString::~MyString(){
    delete[] character;
}
void MyString::resize(size_t n){
    char* pastChar = character;
    if(n > stringCapacity){
        stringCapacity = n;
        delete [] character;
        character = new char[n];
        for (size_t count = 0; count < stringSize; count++){
            character[count] = pastChar[count];
        }
        stringSize = n - 1;
    }
    delete [] pastChar;
}
size_t MyString::capacity() const {
    return stringCapacity;
}

size_t MyString::size() const {
    return stringSize;
}

size_t MyString::length() const {
    return stringSize;
}

char* MyString::data() const {
    return character;
}
bool MyString::empty() const{
    if(stringCapacity == 1){
        return true;
    }
    return false;
}
const char& MyString::front() const {
    return character[0];
}
const char& MyString::at(size_t pos) const {
    if (pos >= stringSize) {
        throw out_of_range("position is not in the range");
    }
    return this->character[pos];
}
void MyString::clear() {
    for (size_t i = 0; i < stringSize; i++) {
        character[i] = '\0';
    }
    stringSize = 0;
    stringCapacity = 1;
}
ostream& operator<<(ostream& out, const MyString& str) {
    out << str.data();
    return out;
}
MyString& MyString::operator=(const MyString& str) {
    delete [] character;
    character = new char[str.capacity()];
    for (size_t count = 0; count < str.size(); count++){
        this->character[count] = str.character[count];
    }
    stringSize = str.size();
    stringCapacity = str.capacity();
    character[stringSize] = '\0';

    return *this;
}
MyString& MyString::operator+=(const MyString& str) {
    if (str.at(0) == '\0') {
        return *this;
    }

    size_t temp = 0;
    while (str.character[temp] != '\0') {
        temp++;
    }
    char* newcharacter = new char[temp + stringCapacity];

    for (size_t i = 0; i < stringSize; i++) {
        newcharacter[i] = character[i];
    }

    for (size_t i = stringSize; i < stringSize + temp; i++) {
        newcharacter[i] = str.character[i - stringSize];
    }

    newcharacter[stringSize + temp] = '\0';

    delete [] character;
    character = newcharacter;
    stringSize = stringSize + temp;
    stringCapacity = stringCapacity + temp;
    
    return *this;
}
size_t MyString::find(const MyString& str, size_t pos) const {
    if (pos >= stringSize || stringSize < str.size()) {
        return -1;
    }
    size_t check = 0;
    for (size_t i = pos; i < stringSize; i++) {
        bool found = true;
        for (size_t j = 0; j < stringSize; j++) {
            if (character[i + j] != str.at(j)) {
                found = false;
                break;
            } 
            check += 1;
            if (check == str.size()) {
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    return -1;
}
bool MyString::operator==(const MyString& str)const{
    if (stringSize != str.stringSize){
        return false;
    }
    for (size_t i = 0; i < stringSize; ++i) {
        if (character[i] != str.character[i]){
            return false;
        }
    }
    return true;
}
MyString& operator+(const MyString& str) {
    return *this += str;
}
