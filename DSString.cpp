//
// Created by mark on 6/2/2021.
//

#include "DSString.h"
#include <iostream>

DSString::DSString() {
    data = nullptr;
}

DSString::DSString(const char *cStr) {

    this->data = new char[strlen(cStr) + 1];
    strcpy(this->data, cStr);

}

DSString::DSString(const DSString &obj) {

    this->data = new char[strlen(obj.data) + 1];
    strcpy(this->data, obj.data);

}

DSString::~DSString() {
    std::cout<< "destructor" << std::endl;
        delete[] this->data;
}

DSString &DSString::operator=(const char *copy) {
    //std::cout << "Char = operator" << std::endl;
    if (this->data != copy) {
        delete[] this->data;
        this->data = new char[strlen(copy) + 1];
        strcpy(this->data, copy);
    }
    return *this;
}

DSString &DSString::operator=(const DSString &copy) {
    //std::cout << "DSString = operator" << std::endl;
    if (this->data != copy.data) {
        delete[] this->data;
        this->data = new char[strlen(copy.data) + 1];
        strcpy(this->data, copy.data);
    }
    return *this;
}

/*DSString &DSString::operator=(const char *copy) {

    if (this->data != copy) {
        //delete data;
        //this->data = new char();
        //strcpy(this->data, copy);
    }
    return *this;
}

DSString &DSString::operator=(const DSString &copy) {

    if (this != &copy) {
        //delete[] data;
        *this->data = *new char[strlen(copy.data) + 1];
        strcpy(this->data, copy.data);
    }
    return *this;
}*/

DSString DSString::operator+(const DSString &a) {
    //std::cout << "Add operator" << std::endl;

    char newStr [strlen(this->data) + strlen(a.data) + 1];
    strcat(newStr, this->data);
    strcat(newStr, a.data);

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
    *newObj.data = *newStr;
    return newObj;
}

char *DSString::c_str() {
    return this->data;
}

std::ostream &operator<<(std::ostream &oFile, const DSString &objPrint) {
    return oFile << objPrint.data;
}