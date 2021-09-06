//
// Created by mark on 6/2/2021.
//

#include "DSString.h"

DSString::DSString() {
    data [0] = '\0';
}

DSString::DSString(const char *cStr) {
    for (int i = 0; i < strlen(cStr); i++)
        data [i] = cStr [i];
}

DSString::DSString(const DSString &obj) {
    for (int i = 0; i < strlen(obj.data); i++)
        data [i] = obj.data [i];
}

DSString::~DSString() {
    //for (int i = 0; i < getLength(); i++)
    //delete data;
}

DSString &DSString::operator=(const char *copy) {

    if (this->data != copy) {
        //delete data;
        //this->data = new char();
        strcpy(this->data, copy);
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
}

DSString DSString::operator+(const DSString &a) {
    DSString newStr;
    *newStr.data = *this->data;
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
    *newObj.data = *newStr;
    return newObj;
}

char *DSString::c_str() {
    return this->data;
}

std::ostream &operator<<(std::ostream &oFile, const DSString &objPrint) {
    return oFile << objPrint.data;
}