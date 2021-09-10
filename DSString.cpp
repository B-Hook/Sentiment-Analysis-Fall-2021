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
    //std::cout<< "destructor" << std::endl;
    if (this->data != nullptr){
        delete[] this->data;
    }

}

DSString &DSString::operator=(const char *copy) {
    //std::cout << "Char = operator" << std::endl;
    if (this->data != copy) {
        //if (this->data != nullptr)
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

DSString DSString::operator+(const DSString &a) {
    //std::cout << "Add operator" << std::endl;

    char newStr [strlen(this->data) + strlen(a.data) + 1];
    strcpy(newStr, this->data);
    strcat(newStr, a.data);

    return newStr;
}

bool DSString::operator==(const char *c) const{
    int a = strcmp(this->data, c);
        if (a == 0)
            return true;
        else
            return false;
}

bool DSString::operator==(const DSString &c) const{
    int a = strcmp(this->data, c.data);
    if (a == 0)
        return true;
    else
        return false;
}
bool DSString::operator!=(const DSString &c) const{
    int a = strcmp(this->data, c.data);
    if (a != 0)
        return true;
    else
        return false;
}

bool DSString::operator>(const DSString &c) const{
    int a = strcmp(this->data, c.data);
    if (a > 0)
        return true;
    else
        return false;
}

bool DSString::operator<(const DSString &c) const{
    int a = strcmp(this->data, c.data);
    if (a < 0)
        return true;
    else
        return false;
}


bool DSString::operator>(const char *c) const{
    int a = strcmp(this->data, c);
    if (a > 0)
        return true;
    else
        return false;
}

char &DSString::operator[](const int index) {
    //if (strlen(this->data) < index) {
        return this->data[index];
    //}
}

int DSString::getLength() {
    return strlen(this->data);
}

DSString DSString::substring(int start, int numChars) {

    DSString newObj;
    newObj.data = new char [numChars + 1];
    memcpy(newObj.data, this->data + start, numChars);
    return newObj;
}

char *DSString::c_str() {
    return this->data;
}

std::ostream &operator<<(std::ostream &oFile, const DSString &objPrint) {
    return oFile << objPrint.data;
}