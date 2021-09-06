//
// Created by mark on 6/2/2021.
//

#include "DSString.h"

DSString::DSString() {

}

DSString::DSString(const char *cStr) {

}

DSString::DSString(const DSString &) {

}

DSString::~DSString() {

}

DSString &DSString::operator=(const char *copy) {

    if (this->data != copy) {
        //deletes the inital pointers
        delete data;
        //then assigns them copies
        this->data = new char();
        strcpy(this->data, copy);
        *data = *copy;
    }
    return *this;
}

DSString &DSString::operator=(const DSString &copy) {

    if (this != &copy) {
        delete[] data;
        this->data = new char[strlen(copy.data) + 1];
        strcpy(this->data, copy.data);
    }
    return *this;
}

DSString DSString::operator+(const DSString &a) {
    DSString newStr;
    newStr.data = this->data;
    strcat(newStr.data, a.data);
    return newStr;
}

bool DSString::operator==(const char *c) {
    return this->data == c;
}

bool DSString::operator==(const DSString &c) {
    return *this == c;
}

bool DSString::operator>(const DSString &c) {
    return *this > c;
}

bool DSString::operator>(const char *c) {
    return this->data > c;
}

char &DSString::operator[](const int index) {
    return this->data[index];
}

int DSString::getLength() {
    return strlen(this->data);
}

DSString DSString::substring(int start, int numChars) {
    
    char newStr [numChars + 1];
    DSString newObj;
    memcpy(newStr, this->data + start, numChars);
    newObj.data = newStr;
    return newObj;
}

char *DSString::c_str() {
    return nullptr;
}

std::ostream &operator<<(std::ostream &, const DSString &) {
    return <#initializer#>;
}